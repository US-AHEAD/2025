# Sparse Switch Matrix

Consider a system that receives 384 12-bit unsigned inputs and route them to 320 outputs. Such connectivity should be configurable and defined by an extra input representing an index for each of the 320 outputs. 
Implementing a 384-to-320 full-mesh crossbar can represent a significant computationcal cost for even large FPGAs. 

One can significantly reduce the connectivity needed evaluating all the practical use cases. The resulting mapping is available in the `ism_cfg.h` file. 

For example, output 0 can be driven by inputs `47,   30,   49,   29,  169,  168,   32,  170,   34`.  If one needs to connect input 49 to output 0, index value 2 should be provided. 

```
{  47,   30,   49,   29,  169,  168,   32,  170,   34,   34,   34,   34,   34,   34,   34,   34},
{  46,   31,   48,   28,   83,   73,   33,   75,   80,   35,   29,   29,   29,   29,   29,   29},
{  45,   28,   51,   31,   61,   88,   35,   89,   60,   33,   34,  383,  220,  220,  220,  220},
{  44,   29,   50,   30,   58,   94,   34,   95,   59,   32,   35,   36,   36,   36,   36,   36},
```

Given that there are at maximum 16 index options for each output, the index input ranges from 0 to 15, therefore 4-bit unsigned index value for each output can be used. This means that each of the 320 384-input MUXes can be replaced to a 16-input MUX.
The final implementation should be aiming low latency.  
For easing the testbench generation, please use `ism_x.csv` an example of random generator of 384 inputs for 100 timestamps. The file `ism_settings.csv` represent the trimmed index being used for each of 116 different use cases. Finally the file `ism_mapping.csv` represents the absolute index of the variable expected at the output of the block.
