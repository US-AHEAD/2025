#!/usr/bin/env python
#
# This script submits jobs to the grid
import os
import subprocess
import numpy as np


import argparse
parser = argparse.ArgumentParser()
parser.add_argument("--outputName", type=str, default="data.txt", help="name of output file")
parser.add_argument("--numTracks", type=int, default=50, help="Number of modules")

args = parser.parse_args()

def main():
    np.random.seed(42)
    f = open(args.outputName, "w")

    for i in range(0, args.numTracks):
        trackID = 0xAA000000+i
        f.write(str(trackID) + "\n")

        numHits = 10
        hits = np.random.uniform(0,75,numHits)
        hits = [int(x) for x in hits]
        hits = list(set(hits))

        hits.sort()
        chiQuad = np.random.uniform(0,10,1)

        f.write(str(chiQuad[0]) + "\n")

        for hit in hits:
            f.write(str(int(hit)) + "\n")



        endString = 0x559922
        f.write(str(endString) + "\n")



    f.close()





# run the main function
if __name__ == "__main__":
    main()
