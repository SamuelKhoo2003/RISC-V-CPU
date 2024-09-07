# Bruno Duaso Personal Statement



### Summary of my main contributions
- Wrote, tested and debugged Single Cycle control module.
- Helped with the debugging of the Single Cycle Design.
- Wrote, tested and debugged Hazard Unit.
- Wrote and connected Pipeline Registers.
- Debugged Pipelined Design.

### Structure 
My personal statement is distributed with the following structure:
- [Single Cycle CPU.](#single-cycle-processor)
- [Pipelined CPU.](#pipelined-processor)
- [If I were to do it again.](#if-i-were-to-do-it-again)
- [What I have learned.](#what-i-have-learned)

## Single Cycle Processor

### Introduction
For this first section of the project, I was mainly involved in the Control Section, with special focus on the [Control Unit](#control-unit) instructions and the [Sign Extender](#sign-extend). I additionally was significantly involved in [debugging](#debugging) and helped with some [miscellaneous tasks](#miscellaneous-contributions).
In this section of the project, progress was slower than anticipated due to a series of unexpected challenges. The need for extensive debugging of various errors significantly impeded our ability to advance at the desired pace.

### Control Unit 
Most of the implementations in this module required a very complete knowledge of 
the CPU logic. To implement most of the instructions I was required to modify 
modules from ``PC`` and ``ALU``. Samuel also helped with the completion 
of this module. Basic instructions (``BNE``, ``ADDI``) where already implemented in the **Lab 4 - A Reduced RISC-V CPU**.
In total, I added:
- **General Changes**: additional instructions (``SSLI``):
    - [New instructions added to Control Unit](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/834a18358ae1cdf8cfb0cc98112358d2e530cdae)
-  **Jump and link instructions** '``JAL / JALR``': These instructions required 
modifications in ``ALU`` and ``PC`` in order to write the ``PC`` value into the 
register, and write it back to ``PCReg``:
    - [ADDED JAL, JALR, +2 cntrl out](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/f00e40925f5c2686d410f8778971ad76006569e1)
    - [Added MUX4 for Memory](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/2a8dd21c2977ef0172c853b4370f74465fd29e6c)
    - [resultMux takes PCPlus4](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/ae0b251e55ad688e03a4163cf2f253ded6abd965)
    - [Added MUX4 for PC](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/d2e969b386d929fbc350fc50698d395cf4109e84)
    - [Connected PCPlus4 & ALUResult](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/caa5ceaf9cf0ee306d6b7fc1b26452550e29f91f)
### Figure 1
![Figure 1](/img/pro.png)

-  **Load instructions** (``LB, LH, LW, LBU, LHU``): these new instructions required additional control bits, to differentiate the ways in which we can write back the register file. WE3 was converted to 3 bits in order to solve this problem, as we read the entire 32 bits from Data Memory, and wrote the appropriate sign extension into the Reg File.
    - [LW, LH, LB instructions](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/d9299d782632e35403d4cb4d405620e68370cdff)
    - [Sign Extension for LB/LH](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/26790233c4c6e1883cf98b9fe9b7fbb13d2068b7)
    - [LBU and LHU instructions - 3'WE3](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/aaf010785579db06aff0df9faa1af513572a3f84)
- **Store instructions** (``SB, SH, SW``): similarly, we need to differentiate between the types of stores into the Data Memory. Mem Write was converted to 2 bits in order to solve this problem.
    - [SB/SH/SW in Control Unit](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/66006e98c32fdff92796b562c4da508c88b55ed0)
    - [Implement byte/half WE data mem](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/5a435b5dee0bca728deb4ccc6681a21f37b07e95)
    - [Updated all instructions with Mem/RegWrt](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/c4428907503a7c99c9b2d555d98924eae0937573)
    - [Updated Mem/RegWrite on top](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/788dbab63870f1117b7aa3d1153d149a254ea664)

### Sign Extend

This module did not require a large number of changes from the version in the **Lab 4 - A Reduced RISC-V CPU**, and implementations were made in collaboration with Samuel. Initially the controls did not match the ones provided in the lectures, which 
caused confusion in the control outputs – this was later modified to have a standard 
model.

- [Modified ImmSrc - J type instructions](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/f5728f330b3652f633b39f4365c50a24844ecae2)
- [Modified ImmSrc to fit the lectures](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/7f46328cc357b9bbfcc757af1cc59ddde4c74ed7)
- [Added S type to Sign Extend](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/1c30e8bf9af03965e23148496c3bd882366de31a)

### Debugging

I additionally helped Vishesh testing, debugging, and fixing various 
issues. A significant portion of these errors were caused by the fact that we had 2 
separate folders – for development and for testing – and very often these folders
were not updated correctly between each other. This was later corrected in the 
Pipelined Section

- [Debug 0](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/8ffeba6d598be992f948ba5090ea9334d4913b1a) - Fixed lengths of Mem/RegWrite
- [Debug 1](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/3a869c5654f869a8f14c76366e7d36491447bb94) - Updated test folder with correct versions 
- [Debug 2](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/e715716693e33b93499ac543f2cfe6661ce90980) - Solved various minor issues 
- [Debug 3](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/b2340bfb9887e843876ee28b1dd1a01024783582) - Fixed lengths of PC wires
- [Debug 4](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/80f14e17dd5b1aff3a132fce4b430e3f41113b66) - Fixed errors in Sign Extend
- [Debug 5](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/3b338939df220d7765b8d59b01f6e053c6bd171b) - Fixed lengths of PC wires
- [Debug 6](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/8c52a1892f3e2972dcda567db35c0f98d9d8f0f1) - Fixed various minor errors 
- [Debug 7](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/a34c6926ed1dc4926eb638c6ddcb68f65f84aeb5) - Corrected Data Mem to include Little Endian Addressing
- [Debug 8](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/555be0d29cbe00211881d412652ff59d9df27441) - Fix Store instructions.

### Miscellaneous Contributions

- **Created Figure 1** ([shown above](#figure-1)):having an image reference of the new module 
configuration for the ``JAL/JALR`` instructions helped to implement the 
changes and avoid errors in the wiring.
- **Coded F1 light sequence code**, which was later modified and implemented by Vishesh and Anson.
- **Coded Python Script** to separate word instructions into bytes, in the 
correct order to be fetched into the ``InstrMem``. I also modified InstrMem 
to fit Little Endian Addressing
    - [Python Script - Words to bytes](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/26790233c4c6e1883cf98b9fe9b7fbb13d2068b7)

## Pipelined Processor
For this second section of the project, I implemented the 2 new sections need: 
- [Pipeline Registers](#pipeline-registers)
- [Hazard Unit](#hazard-unit) 
I also initially renamed and rewired all the signals to fit the starting diagram, which 
would later be greatly modified and improved.

![pipelined](/img//pipelined.jpg)

Additionally, I greatly contributed to [debugging](#debugging-1) efforts with Vishesh, and helped 
Samuel with some specific issues for the improved [Control Unit](#control-unit-1).

### Pipeline Registers 
Initially I implemented a single pipeline register per stage, with the thought that 1 was 
simpler than 2. But each single register had a very large number of signals, so I 
opted to have separate registers for control and data. This was suggested by 
Samuel, and it turned out to be much cleaner and easier to debug.
The pipelining process very was time consuming, but relatively straight forward. 
Having a special label in each signal for the different cycles importantly decreased 
debugging time and confusion. Here are the main commits of these implementations: 
- [Freg](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/009bf1eaafb51359a63a555d26bf9a86a6fcbeec)
- [Wiring 1](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/0fd04426abfd7518fbb5c0fb1aa0a1ad00eda1c1)
- [Dreg](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/cde1c066b335c0c87a36d75755ba65f3a83ed19b)
- [Ereg](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/3498956f0990207ed4e655b2043cc02c515cf19b)
- [Wreg](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/2c46d6fa612d581b0c166c84e5bddded659c76da)
- [Separate Registers in Control and Data](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/00e38bbfe15e397dae57fa8b022b063303ae2bc6)

### Hazard Unit
I was also in charge of the logic for both [data](#data-hazards) (divided into stall and forward), and 
[control hazards](#control-hazards). For simplification purposes, each section was divided into its own 
module, inside the hazard unit. Here are the main commits for this module: 
- [Module Creation](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/b7749837c6c3849c09427c18a9596e436d76dea3)
- [Initial Forward and Stall Units](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/35aafbf6250ee00b89374778b27894b049db0144)
- [Hazard Control](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/d5efce9f1bbb1f3eb2a22ccfcfe27a487f384385)
- [Wiring 1](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/33c9b00514c2054ed761444feb61624c9ce27b74)
- [Rst/Flush Signals](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/f6f1b2fa4f7ad0b4072a9c08f5e4e886cd33698c)
- [Not hazard if Zero](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/362a922ca187f69ff2a1a4ae853635666d1fe460)
- [Improved hazard Unit](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/ffca89cbbd4b4376f6f3d5942ac3d6c5485ebb1b)
- [Improved hazard stall](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/dde6d5f3ff09d9034e1cc68c1f721804e12cf6d5)
- [Corrected hazard stall](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/a3fae947d1e87687594b2405088e6f8af4233133)

#### Data Hazards
Aside from detecting a match between registers, and an intention to write back, we need take into account the type of the instruction, for both Stalls and Forwards to prevent mistaking an immediate for a register. We do this by reading ImmSrc (delayed by one cycle), and appropiately adjusting our logic:

![img1](/img/bruno1.png)

Stall:
```
assign A = ((ImmSrcE!=3'b100)&&(ImmSrcE!=3'b011));
assign B = (A)&&(ImmSrcE!=3'b000);
assign PCen = (((opcodeE == 7'd3) && ((RdE == Rs1D)&&A  || (RdE == Rs2D)&&B))? 0 : 1);
assign Fen  = (((opcodeE == 7'd3) && ((RdE == Rs1D)&&A  || (RdE == Rs2D)&&B))? 0 : 1);
assign Drst  = !(((opcodeE == 7'd3) && ((RdE == Rs1D)&&A  || (RdE == Rs2D)&&B))? 0 : 1);
```
Forward
```
assign A = ((ImmSrcE!=3'b100)&&(ImmSrcE!=3'b011));
assign B = (A)&&(ImmSrcE!=3'b000);

assign FowardAE = ((RegWriteM) || (RegWriteW&&A)) ? (((Rs1E == RdM)&&(Rs1E!=5'b0))? 2'b10 : (((Rs1E == RdW)&&(Rs1E  != 5'b0)) ? 2'b01 : 2'b00)) : 2'b00;
assign FowardBE = ((RegWriteM) || (RegWriteW&&B)) ? (((Rs2E == RdM)&&(Rs2E!=5'b0)) ? 2'b10 : (((Rs2E == RdW)&&(Rs2E != 5'b0)) ? 2'b01 : 2'b00)) : 2'b00;

```

 - **Forwarding**: There are mainly two points to note. In case of conflict, we need 
to prioritize forwards from ``M`` to the ones from ``W``, as they contain the latest, corrected data to forward. 
And, we need to make sure that the register where the hazard is caused is different from zero (reading from zero never results in a 
hazard).

![img2](/img/bruno2.png)

- **Stalling**: this module is very straightforward. We use `opcode` to detect a 
load instruction, and use `RdE` and `Rs1D`/`Rs2D` to detect a match. When that 
happens, we want to stall ``PCreg`` and ``Decreg``, and flush the content in the execute register.

#### Control Hazards:
Also very simple. Whenever we branch or jump `(PCSrc !=0)`, we need to Flush the 
content of the Fetch and Decode registers.
```
assign Frst = (PCSrcE != 2'b0) ? 1 : 0;
assign Drst = (PCSrcE != 2'b0) ? 1 : 0;
```

### Control Unit
Samuel greatly cleaned and improved the control unit, I fixed specific issues such as:

**LBU instruction**: In Single Cycle, for all the Load instructions, we took the whole 32 
bits from ``DataMem`` and we wrote the appropriate extension to ``RegWrite`` according to 
``WE3``. This was no longer possible in pipelining due to Forwarding Hazards. We 
solved this by getting rid of all the (unused) load instructions, and SW instruction. 
This allowed us to set ``WE3`` in ``RegiterFile`` back to 1, and we used the extra bit in 
RegMem to implement LBU correctly.

**LUI instruction**: small modifications where needed in ``ALU`` and ``ALUdecoder`` to 
correctly implement this instruction.
- [LUI in ALU and ALUdecoder](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/fafbd1101bb423987224f288050e2d2b3705a6ce)

**PCSrcE logic**: implemented logic to determine the correct ``Branch``/``Jump``. We need 
to take into account the correct Branch instruction ``(BNE/BEQ)`` and adjust ``ZeroOP`` 
accordingly. I also used ``ALUSrcE`` to differentiate between ``JAL`` and ``JALR`` instruction 
without the need for additional logic.
```
assign ZeroOp = ZeroE_i ^ funct3E[0]; // flip the Zero input if BNE

always_comb
    if (JumpE)      PCSrcE_o = ALUSrcE_o ? 2'b10: 2'b01 ; //choose between JAL and JALR without extra logic
    else PCSrcE_o = (BranchE & ZeroOp) ? 2'b01 : 2'b00;
```
- [Initial PCSrcE logic](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/d0200ea5f6bc5a4f4f9d8affa304f1450ee1c708)

**Store and Load instructions**: added cases to identify the separate Store and Load 
instructions (that were later not included) to the new and improved control_top.
- [Store and Load](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/8d65682cc29ffa8cba8c69ee9e6d73afa185a612)

### Debugging
This was undoubtedly the most tedious and time consuming contribution to this 
section. The initial logic had multiple issues, and finding those specific errors was not 
easy. 
Vishesh, who mainly debugged Single Cycle, made this process a lot easier as 
multiple issues where repeated in both sections (such as Data Memory being word 
addressed, instead of byte addressed).

- [Debug 1](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/4aa25ff3a87266d9daadd5c65949c5438bc23df8) - syntax errors
- [Debug 2](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/9c783802bcc7d2eeba3b44668bd32d01ece776c9) - Fixed 54 various errors
- [Debug 3](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/99a35a97144e334eed66a035cdede3818545d225) - Fixed multiple syntax and wiring errors
- [Debug 4](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/e9d25729eba150552333bec1b9e4c0ac1653c812) - Stall hazard errors
- [Debug 5](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/0a8c811314abaa4e6a9a5157425ce836848b01f5) - Issues with JAL
- [Debug 6](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/5549c4a14c75f9e6c38bae284dde9a2d2b1bd558) - Incorrect wiring to RegFile A3
- [Debug 7](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/c137ad57e79baafbf7134aac8fb11ac4b1fc6caf) - Corrected control for I type instructions
- [Debug 8](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/200b652a0ad7c520aebf310bc4cd309ab96b8cf7) - Zero has to be constant 0.
- [Debug 9](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/eeb03f3968d7c0fe007c33d3af2796ea5a0b072d) - Fix LBU
- [Debug 10](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/2c54ef389c285219b5301eaa878303c9f7dbf845) - Fix RegWrite

### If I were to do it again
In general, I am pleased with the approach taken. Maybe I could have researched
the specific modules before writing them, instead of trying to figure them out by 
myself – that would have saved me multiple hours debugging. But I fundamentally 
think that running into problems and having to work out a solution has been a key 
aspect of the learning process. 
If I had to change something, I would have focused more on communicating with my 
team. At times we were working on the same things at the same time, which reduced 
our efficiency as a Team. But overall, we maintained a great relation, and are 
pleased with the end result. 

### What I have learned

This was a project that, although at times seemed tedious and endless, was overall
very enjoyable. There where multiple creative opportunities and design decisions 
that kept it very dynamic and engaging. The project was structured in such a way that 
you could learn from it as much as the effort invested, which maintained me hungry for improvements
and additions, as you could actively see your effort being transformed into progress.

Undoubtedly, I feel I have a very deep understanding of the fundamentals of System 
Verilog, CPU design and logic, and GIT hub. The latter was an especially helpful 
lesson, that I have already starting using more frequently for parallel personal 
projects. Additionally, I learned Markodown language, which I now frequently use 
to take notes in Obsidian.

Another very important learning point was communicating and working as a team. I 
learned the importance of task distribution and efficient communication. 

As a conclusion, I am very happy about this project. I think it was very well 
structured, and I truly learned and engaged with the material covered.