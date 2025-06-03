# Task
This is an actual kernel that is part of the ATLAS EF tracking project, that performs strip clustering.

In this task, the idea is to compile this kernel, test it, profile it and find areas for optimization. 

The workflow is a bit different, in the sense that we don't have a Vitis GUI project. Rather we use a makefile to compile, and a command line host code to run the project. 

You can enable profiling by following the instructions at https://docs.amd.com/r/en-US/ug1700-vitis-accelerated-data-center/Enabling-Profiling-in-Your-Application

And example of how to use optimization tools can be found at https://xilinx.github.io/xup_compute_acceleration/Optimization_lab.html

## Data
```
# these paths need to be updated for the server under testing
source /opt/xilinx/xrt/setup.sh
source /opt/xilinx/Vitis/2024.1/settings64.sh`

cd src
make EMU_MODE=hw_emu
source export.sh

./host StripClustering.xclbin processHits <path to input TV> <path to output TV> <max module>
```

The test vectors for testing are provided in the "testbench" folder. There are two set, a large and small TV. If you are using the smallTV, the max module should be set to -1, so you get all the modules.

If you are using the large TV, you can set this number to a small number to pick that make data lines out of the large TV. -1 will give you all of them
