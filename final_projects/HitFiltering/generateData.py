#!/usr/bin/env python
#
# This script submits jobs to the grid
import os
import subprocess
import numpy as np


import argparse
parser = argparse.ArgumentParser()
parser.add_argument("--outputName", type=str, default="data.txt", help="name of output file")
parser.add_argument("--numModules", type=int, default=10, help="Number of modules")
parser.add_argument("--numHitsPerModule", type=int, default=50, help="Average number of hits per module")

args = parser.parse_args()

def main():
    np.random.seed(42)
    f = open(args.outputName, "w")

    for i in range(0, args.numModules):
        moudleID = 0xFF000000+i
        f.write(str(moudleID) + "\n")

        numHits = np.random.poisson(lam=args.numHitsPerModule, size=1)[0]
        hits = np.random.uniform(0,200,numHits)

        for hit in hits:
            f.write(str(int(hit)) + "\n")



        endString = 0x667744
        f.write(str(endString) + "\n")



    f.close()





# run the main function
if __name__ == "__main__":
    main()
