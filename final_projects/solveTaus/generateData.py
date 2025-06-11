#!/usr/bin/env python
#
# This script submits jobs to the grid
import os
import subprocess
import numpy as np


import argparse
parser = argparse.ArgumentParser()
parser.add_argument("--outputName", type=str, default="data.txt", help="name of output file")
parser.add_argument("--numEvents", type=int, default=2, help="Number of events in the test file")
parser.add_argument("--gridSize", type=int, default=10, help="grid size of your cluster")

args = parser.parse_args()



def main():
    np.random.seed(42)
    f = open(args.outputName, "w")

    for i in range(0, args.numEvents):
        eventID = 0xAA0000AA
        f.write(str(eventID) + "\n")


        for j in range(0, args.gridSize):
            clusterEnergies = np.random.uniform(0,200,args.gridSize)
            for k in range(0, args.gridSize):

                if(clusterEnergies[k] < 20):
                    continue

                f.write(str(int(j)) + " ")
                f.write(str(int(k)) + " ")
                f.write(str(int(clusterEnergies[k])) + "\n")



        footerID = 0xFF0000FF
        f.write(str(footerID) + "\n")



    f.close()





# run the main function
if __name__ == "__main__":
    main()
