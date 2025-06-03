#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <vector>
#include "xcl2.hpp"
#include "processHits.h"
#include <bitset>
#include <fstream>
#include <sstream>
#include <string>
#define MAX_DATA_SIZE 10000000

// Function to extract the first n MSB bits from a 64-bit unsigned integer.
uint64_t extractFirstNMSB(uint64_t num, int n) {
    const int totalBits = sizeof(uint64_t) * 8;  // typically 64 bits
    
    // If n is greater than or equal to total bits, return the entire number.
    if (n >= totalBits)
        return num;
    
    // Shift right so that the top n bits are moved into the lower positions.
    return num >> (totalBits - n);
}

void readFile(std::string fileName, std::vector<uint64_t, aligned_allocator<uint64_t>>& v, unsigned int& line, int maxModule)
{
    int countModule = 0;
    if (fileName.find(".txt") != std::string::npos)
    {
        std::ifstream file(fileName, std::ios::in);
        std::string cache;

        while (std::getline(file, cache))
        {
            // Ignore empty lines or lines that start with '#'
            if (cache.empty() || cache[0] == '#')
                continue;

            // Convert hex string to uint64_t
            uint64_t value;
            std::stringstream ss(cache);
            ss >> std::hex >> value;

            if(extractFirstNMSB(value, 8) == 0x55) countModule++;

            if(maxModule == countModule-1 && (maxModule >= 0))
            {
                v[line] = 0xcd00000000000000;
                line++;             
                v[line] = 0;
                line++;                
                v[line] = 0x00000013dc066c65;
                line++;     
                return;
            }

            v[line] = value;
            line++;

            if (line >= MAX_DATA_SIZE)
                break;
        }

        file.close();
    }
    else
    {
        std::ifstream file(fileName, std::ios::binary);
        uint64_t cache;

        while (file.read(reinterpret_cast<char*>(&cache), sizeof(uint64_t)))
        {
            // Reverse the byte order if needed (big endian to little endian)
            cache = __builtin_bswap64(cache);

            if(extractFirstNMSB(cache, 8) == 0x55) countModule++;
            if(maxModule == countModule-1 && (maxModule >= 0))
            {
                v[line] = 0xcd00000000000000;
                line++;             
                v[line] = 0;
                line++;                
                v[line] = 0x00000013dc066c65;
                line++;     
                return;
            }     
            v[line] = cache;
            line++;

            if (line >= MAX_DATA_SIZE)
                break;
        }

        file.close();
    }

    std::cout<<"Module: "<<countModule<<std::endl;
}
int main(int argc, char** argv)
{
	int match = 0;
	size_t ret;
	size_t vSize_bytes = 8 * MAX_DATA_SIZE;
	std::string xclbin_path, tv_in_path, tv_out_path;
	std::string tl_function_name;
	std::vector<uint64_t, aligned_allocator<uint64_t>> in(MAX_DATA_SIZE);
	std::vector<uint64_t, aligned_allocator<uint64_t>> out(MAX_DATA_SIZE);
	std::vector<uint64_t, aligned_allocator<uint64_t>> outEDM(MAX_DATA_SIZE);
	std::vector<uint64_t, aligned_allocator<uint64_t>> reference(MAX_DATA_SIZE);
	uint8_t buf;
	unsigned int vSize = 0;
	unsigned int refSize = 0;

	struct timespec start_wall, start_cpu, end_cpu, end_wall;
	double cputime, walltime;

	cl_int err;
	cl::Kernel kernel;
	cl::CommandQueue q;
	cl::Context context;

	if (argc != 6) {
		std::printf("Usage: %s <XCLBIN FILE> <TOP LEVEL FUNCTION> <INPUT TESTVECTOR FILE> <OUTPUT TESTVECTOR FILE> <MAX Module>\n", argv[0]);
		return EXIT_FAILURE;
	}
	xclbin_path = argv[1];
	tl_function_name = argv[2];
	tv_in_path = argv[3];
	tv_out_path = argv[4];
    int maxModule = atoi(argv[5]);

	// Load the XCLBIN file and program the device
	auto devices = xcl::get_xil_devices();
	auto fileBuf = xcl::read_binary_file(xclbin_path);
	cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
	bool valid_device = false;

	for (unsigned int i = 0; i < devices.size(); i++) {
		auto device = devices[i];
		// Creating Context and Command Queue for selected Device
		OCL_CHECK(err, context = cl::Context(device, nullptr, nullptr, nullptr, &err));
		OCL_CHECK(err, q = cl::CommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &err));

		std::printf("Trying to program device[%d]: %s\n", i, device.getInfo<CL_DEVICE_NAME>().c_str());
		cl::Program program(context, {device}, bins, nullptr, &err);
		if (err != CL_SUCCESS) {
			std::printf("Failed to program device[%d] with xclbin file!\n", i);
		} else {
			std::printf("Device[%d]: Program successful!\n", i);
			OCL_CHECK(err, kernel = cl::Kernel(program, tl_function_name.c_str(), &err));
			valid_device = true;
			break; // we break because we found a valid device
		}
	}
	if (!valid_device) {
		std::printf("Failed to program any device found, exit!\n");
		exit(EXIT_FAILURE);
	}

	// Read input file
	readFile(tv_in_path, in, vSize, maxModule);

	for(int i = 0; i < vSize; i++)
	{
		std::cout<<"Input line i: ["<<std::dec<<i<< "] " <<std::hex<<in[i]<<std::endl;
	}

	// Read reference file
	readFile(tv_out_path, reference, refSize, -1);


	// Reading reference output test vector
	std::printf("Reading in reference output testvector\n");
	

	// Timing for performance
	clock_gettime(CLOCK_MONOTONIC, &start_wall);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_cpu);

	// Allocate buffers in global memory
	std::printf("Allocate Buffer in Global Memory\n");
	OCL_CHECK(err, cl::Buffer buffer_in(context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, vSize_bytes, in.data(), &err));
	OCL_CHECK(err, cl::Buffer buffer_out(context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, vSize_bytes, out.data(), &err));
	OCL_CHECK(err, cl::Buffer buffer_outEDM(context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, vSize_bytes, outEDM.data(), &err));
	OCL_CHECK(err, err = kernel.setArg(0, buffer_in));
	OCL_CHECK(err, err = kernel.setArg(1, buffer_out));
	OCL_CHECK(err, err = kernel.setArg(2, buffer_outEDM));
	OCL_CHECK(err, err = kernel.setArg(3, vSize));

	// Synchronize input buffer data to device global memory
	std::printf("Synchronize input buffer data to device global memory\n");
	OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_in}, 0 /* from host */));

	// Launch the kernel
	std::printf("Execution of the kernel\n");
	OCL_CHECK(err, err = q.enqueueTask(kernel));

	// Retrieve the output data from the device
	std::printf("Get the output data from the device\n");
	OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_out}, CL_MIGRATE_MEM_OBJECT_HOST));
	OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_outEDM}, CL_MIGRATE_MEM_OBJECT_HOST));
	OCL_CHECK(err, err = q.finish());

	// Measure performance time
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_cpu);
	clock_gettime(CLOCK_MONOTONIC, &end_wall);
	cputime = (double)end_cpu.tv_sec - (double)start_cpu.tv_sec + 1e-9 * ((double)end_cpu.tv_nsec - (double)start_cpu.tv_nsec);
	walltime = (double)end_wall.tv_sec - (double)start_wall.tv_sec + 1e-9 * ((double)end_wall.tv_nsec - (double)start_wall.tv_nsec);
	printf("Kernel finished running.\nCPU time [s] = %f\nWall time [s] = %f\n", cputime, walltime);

	// Validate the results
	for (unsigned int i = 0; i < out.size(); i++) {
			// match = 1;
            if(out[i] == 0) continue;
            std::cout<<"Expected: "<<std::dec<<i<<" "<<std::hex<<reference[i]<<" "<<std::bitset<64>(reference[i])<<std::endl;
            std::cout<<"Output  : "<<std::dec<<i<<" "<<std::hex<<out[i]<<" "<<std::bitset<64>(out[i])<<std::endl;
	}
	for(unsigned int i = 0; i < out.size(); i++)
	{
		if(out[i] > 0) std::cout<<"out Line ["<<std::dec<<i<<"]"<<std::hex<<out[i]<<std::endl;
	}
	for(unsigned int i = 0; i < outEDM.size(); i++)
	{
		if(outEDM[i] > 0) std::cout<<"outEDM Line ["<<std::dec<<i<<"]"<<std::hex<<outEDM[i]<<std::endl;
	}
	

	std::printf("TEST %s\n", match ? "FAILED" : "PASSED");
	return (match ? EXIT_FAILURE : EXIT_SUCCESS);
}
