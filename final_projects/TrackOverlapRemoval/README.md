# Task
In this task, you are tracks that simulate what we will see in ITk at the EF Tracking level. Within these tracks, there is a chi-square and a list of hits for each track that is provided. The task is to read this input data, find track that have overlapping hits. If even one overlapping hit is found, we only have to reject the track with the higher chi-square.

After you have written this code, perform resources and timing analysis. Find a way to optimize it


## Data
The data is provided in the following format in data.txt
```
TrackID
Chi-Square
Hit
Hit
Hit
...
Hit
0x559922
TrackID
...


```

The trackID is composed as 0xAA000000+index. The 0xA at the start is to provide an easy identifier to specify that the line tells you its a track identifier. 

Afterwards, there is the chi-square and a variable number of hit index t The end of the hits is specified by a special end of track line, which is 0x559922

The output should be tracks with no overlapping hits in the same format