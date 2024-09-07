
# RISC V CPU

This repository is part of an IAC Module for Imperial where we are required to design a single cycle processor, and then further designing a pipelined processor (with data memory cache and hazard unit).

### Note to examiner
Our folder was structured slightly differently since we didn't use any branching
- We have 3 folders 
    - `reduced_risc_v` refers to our Lab 4 processor design
    - `single_cycle` refers to our single cycle design (actual source of our processor)
    - `test` refers to all the different single cycle design tests that we run
    - `pipelined` refers to the pipelined version of our processor 
    - `img` refers to all our images and videos used throughout our .md files 
    - `statements` refers to our teams Personal Statements

## Joint Statement
As team we have successfully designed and built a single cycle and a pipelined version and we have all gone really far as a team. We've met up regularly across the weeks to properly discuss our design and architecture and we are happy with what we have produced.

To highlight why we have structured this repo through folders instead of branches, is because it was simpler to commmit to just one branch and that it was easier to coordinate with. 

## High Level Description

- Design a single cycle processor that executes couple of RISC V instructions
- Instruction is fetched from Program Counter and Instruction Memory
- Instruction is decoded and is manipulated to determine what operation to perform 
- The ALU and Register file receives the operands from the instructions
- ALU executes instructions and result is stored back to the specified register file 
- Program Counter increments and next instruction is loaded

## Team Members and Distribution of Tasks

| Team members         | Primary Task assigned                                                 |CID        | Personal Statements                                                         | Emails         |
|----------------------|-----------------------------------------------------------------------|-----------|-----------------------------------------------------------------------------|----------------|
| Chin Jun Yen (Anson) | Writing README.md file, ALU and register files                        |02194736   |[Anson's Personal Statement](/statements/AnsonChinPersonalStatement.md)      |ayc122@ic.ac.uk |
| Bruno Duaso          | Writing logic for control unit, sign extension and instruction memory |02321480   |[Bruno's Personal Statement](/statements/BrunoDuasoPersonalStatement.md)     | bd922@ic.ac.uk |
| Vishesh Mongia       | Testbench and verification of design                                  |02288840   |[Vishesh's Personal Statement](/statements/VisheshMongiaPersonalStatement.md)|vm622@ic.ac.uk  |
| Samuel Khoo Ing Shin | PC and related addresses                                              |02264291   |[Samuel's Personal Statement](/statements/SamuelKhooPersonalStatement.md)    |ssk122@ic.ac.uk |

Linked [here](/statements/taskdistribution.md) is a more detailed version of the dsitribution of tasks within our group

## Single Cycle Processor

![Image](/img/pro.png)

### Explanation of F1 Program 

This is a basic program that counts the neopixel lights up by shifting left, then adding 1. The stored a0 value should be hence: 1, 3, 7...

We first run through a main program that jumps to the init function
```
main:
    JAL     ra, init            # jump to init, ra and save position to ra
init:                           # initialise light
    LI      t0, 0xFF            # temp register
    RET
```

The temp register is then changed to set up for the forever section where build and loop2 is looped and outputted forever
```
forever:
    JAL     ra, build
    JAL     forever

build:                          # function to build prob dist func (pdf)
    LI      a0, 0               # begin with all lights off
    LI      t1, 0   
_loop2:                         # repeat till all lights on
    SLLI    t1, t1, 1 
    ADDI    t1, t1, 1
    ADDI    a0, t1, 0
    BNE     a0, t0, _loop2      # until all lights are on
    RET
```

## How to run test file

### PDF Program


Gaussian.mem is loaded into the data array by default.
To edit the data array change line 25 in `test/pdf/data_mem.sv`

> Note: that this testing instruction is only valid for the `test/pdf` folder


To run the pdf reference program:
```
$ source ./pdf.sh
```

### F1 Program

> Note: that this testing instruction is only valid for the `test/f1` folder


To run the F1 program:
```
$ source ./f1.sh
```

### Pipelined programs

The pipelined processor is loaded to run the reference program with the gaussian.mem input.

To change to the f1 program edit /pipelined/instr_mem.sv line 17 to "f1.mem"

To change the pdf input edit /pipelined/data_mem.sv line 27

Then go to the directory:
```
cd RISC-V-Team1/pipelined
```

To run the F1 program:
```
$ source ./f1.sh
```

To run the pdf reference program:
```
$ source ./pdf.sh
```



## Evidence and Results of Program

### Running Gaussian.mem 
![Gaussianimg](/img/gaussianmem.jpg)

### Running Noisy.mem
![Noisy](/img/noisymem.jpg)

### Running Triange.mem
![Triange](/img/triangemem.jpg)

### Running Sine.mem 
![Sine](/img/sinemem.jpg)

### Running F1 Program
Please refer to the video of the F1 start light sequence found in the path: `img/f1video.mp4`


> Further images and videos can be found in the `img` folder 










