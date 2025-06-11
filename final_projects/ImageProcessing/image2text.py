#!/usr/bin/env python3
import numpy as np
from PIL import Image
import sys

if len(sys.argv) != 3:
    print("Usage: python script.py input_image output_text")
    sys.exit(1)

input_file = sys.argv[1]
output_file = sys.argv[2]

np.savetxt(output_file, np.array(Image.open(input_file).convert('L')), fmt='%d')
