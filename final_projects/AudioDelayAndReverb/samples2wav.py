#!/usr/bin/env python3
# samples2wav.py input.txt output.wav writes a Wav file from 
import sys, struct, wave

with open(sys.argv[1]) as f, wave.open(sys.argv[2], 'wb') as w:
    w.setnchannels(2)  # 2 for stereo
    w.setsampwidth(2)  # 2=16 bit dynamic range (see also 32767 below)
    w.setframerate(48000)  # 48 kHz sampling rate
    
    for line in f:
        # Split each line by whitespace and convert to floats
        values = line.strip().split()
        if len(values) >= 2:
            left = float(values[0])
            right = float(values[1])
            # Pack and write frame immediately
            frame = struct.pack('<hh', int(left * 32767), int(right * 32767))
            w.writeframes(frame)
