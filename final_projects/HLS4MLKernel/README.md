# Task
Take the HLS generated code and compile it in Vitis. Perform feed data through, and perform timing analysis of this. See if you can find ways to optimize it

## Background info
This is an actual kernel that is designed to predict track parameters on FPGAs for the ATLAS EF tracking project. It takes in hit position along a track, and given pT/eta/phi/d0/z0 as the output

## Data
Input data is provided in data.txt. The format goes:

```
x1 y1 z1 x2 y2 z2 ....xM yM zM
pt eta phi d0 z0
x1 y1 z1 x2 y2 z2 ....xM yM zM

...
pt eta phi d0 z0
```


The first line is the input, where the M hits on a track are given. The kernel provided will only take 5 of these hits as input
The output is are the 5 track parameters. 

This format is repeated a few times in the file. If you need more data, contact Haider
