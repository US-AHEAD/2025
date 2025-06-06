# Task
In this task, you are given hits which are simulating data from the ITk Strip detector. 

However, during construction we know some of the modules are noisy, so the task is to filter these hits and only output the ones that are not masked. List of channels to mask are provided belwo

After you have written this code, perform resources and timing analysis. Find a way to optimize it

## Channels to mask
module 1: [10-15, 100-150]
module 3: [20-49]
module 4: [18-56]
module 6: [85-193]
module 8: [5-10, 20-37, 198-200]
module 10: [5-21]

## Data
The data is provided in the follwing format in data.txt
```
moduleID
Hit
Hit
Hit
...
Hit
0x667744
moduleID
...


```

The moduleID is composed as 0xFF000000+index. The 0xFF at the start is to provide an easy identifier to specify that the line tells you a module identifier. 

Afterwards, there are a variable number of hits that are in the module for you to mask. The end of the hits is specified by a special end of module line, which is 0x667744


The output should be in the same format as this