# Vishesh Mongia Personal Statement 

## Introduction
In this project I focussed on debugging our RISC-V CPU by creating testbenches to troubleshoot and visualise our outputs on the Vbuddy. My tasks led me to have an overarching understanding of this architecture and how we interact with a model of a cpu using c++ testbenches along with verilator. 
Ensuring functionality of each submodule and in turn our processor was a tedious task, but over time while getting experienced with various debugging techniques and GTKwave I found this coursework extremely rewarding and beneficial to my knowledge of computer architecture.


### Structure 
My personal statement is distributed with the following structure:
- [Single Cycle CPU](#single-cycle-processor)
- [Pipelined CPU](#pipelined-processor)
- [What I have learnt](#what-i-have-learned)

## Single Cycle Processor

### Summary of contributions:
- Created top cpu.sv file and connected submodules 
- Debugged and organised single cycle processor
- Created F1 lights program which is used in the final submission
- Created testbenches to debug and test modules
- Used Vbuddy to visualise F1 and PDF programs
- Editing the final layout for the submission

We started this project by forking our initial lab 4 repo which saved time in the short term in order to fast track our progress. I soon found out that the teams initial SystemVerilog code was quite messy and convoluted due to our inexperience. This meant that my earlier debugs were more oriented towards making our code clearer by adding _i and _o to respective inputs and outputs and organising our wires between modules. This process got me into the correct frame of mind, understanding verilog errors and utilising GTKwave to find potential errors.

[Organising our top file](https://github.com/vishesh32/RISC-V-Team1/commit/68ab86416fa8fdee26f721dac506706ee60bb87a#diff-a5b41f44cfd3cb4f925de3fba8bf2366f03d587af431da1f2a968f6d1f142e7c) 

[Renaming inputs/outputs](https://github.com/vishesh32/RISC-V-Team1/commit/ff227ca86d1d32d87d62c8945060bac88d7e2456)

[Fixing overlooked errors](https://github.com/vishesh32/RISC-V-Team1/commit/669c8329cf2fb342263f5a69cf980751736d20af#diff-e48e3546c80833f34c5470360580103750305bdcf2e9193510eb8d7f2bbde4c0)


Once all the errors and warnings thrown by the compiler were sorted, this next stage of debugging really tested my understanding of how each submodule interacts with another. The types of problems now were rooted deep into the code, more often than not being a very small logical or wiring error. These initially were difficult to trace but going through the lectures and other resources aided me to understand what output we expected at each point of the datapath, allowing me to find the bug usually in places where the code seemed correct.

[Similar wire names caused our ALU to fail, the fix being a simple wire swap](https://github.com/vishesh32/RISC-V-Team1/commit/40fb9a01b181969fc3bcd5cecaf08c212c2f22c7)

[Zero register was editable causing the F1 program to fail](https://github.com/vishesh32/RISC-V-Team1/commit/7b76e8eabcef086eafbc0161d783de015912eaf0#diff-bb57bdecb9a66f37a77e7de626aa400f6dd06d72694f9f7a7869177c73050ccd)

[ALUResult_o wire was missing](https://github.com/vishesh32/RISC-V-Team1/commit/ee3688a3077f39d4556329badb9a380c97852d14)


I edited the given PDF.asm reference program in order to create the F1 lights program. I felt this was the correct choice to implement our code as the PDF program had a clear structure and forever loop that made sense to utilise. I removed majority of the loops in the reference program and had an init loop and the main program forever loop. 

[F1 Program creation](https://github.com/vishesh32/RISC-V-Team1/commit/ba90b9c932143bd153683d2fccdc1d1fc76d6c3f#diff-8b74cc38b225d9f95005d274e5ff13668225b1cc4c05484bdb5a5b4a59537291)


We were now ready for the final testing of the single cycle and so I created two separate testbenches, one for the F1 program and another for the reference. Currently these are split into two folders within the test folder for clarity. I used additional c++ libraries - "chrono" and "thread" - in order to create a time delay between the activation of each F1 light.

[Testbench for F1 program](https://github.com/vishesh32/RISC-V-Team1/commit/3038b23fe0a94ad7e4facc1f02c4a1179d1cac00#diff-e859aa56ca8c1855ffce026b76ec795abe12a25407466697dcc655fc43b00e33)

[Testbench for reference program](https://github.com/vishesh32/RISC-V-Team1/commit/43a4b6f1dc5ff7042e805b6d4d1c9882f3ba43e3#diff-997feeff3adda4cd164da68da920683e8039fa54fa0a5f9b7415b386d026bbdc)


Our F1 program worked as expected from the start but our Reference program had errors in the PDF array being created. This error was extremely difficult to trace as we were certain all our instructions worked. The problem was that the PDF array had many 0's stored where it should have been incremented, resulting in a poor plot onto our Vbuddy. Using the Vbuddy to always visualise the waveform was quite tedious so I started using c++ fstream to output the a0 and pdf array. This meant that I had to add an extra debug output in the data_mem.sv. Over time I corrected a sequence of errors related to our byte addressing in the data memory. This experience assisted me further in debugging the pipelined outputs as that was much more complicated to figure out using just GTKwave.


### Waveform issue
![Deformed Gaussian wave](/img/oldgaussianpdf.jpeg)

We were missing plots on the wave resulting in it looking very sparse. This was a result of byte addressing not working correctly.


[Adding extra debug output in data_mem.sv to output into a txt file](https://github.com/vishesh32/RISC-V-Team1/commit/9de16006144ae5cd6d0baf685f668e9ad2091b82#diff-31daeb11b62db69aa0502be4a304a132ba9bf9a4629491d219ec76bf2d746217)

[Fixing first byte addressing error](https://github.com/vishesh32/RISC-V-Team1/commit/abd7312baead78132a8efb9f787bccfb50df613e#diff-039cbe711c4af51a6b8aeefc96864f1d3387634f62327fb18489c33c4c6ff7e1)

[Fixing the loading of the sample sine.mem data](https://github.com/vishesh32/RISC-V-Team1/commit/e40d133ff82b5acb28266b42195326ec2e90a55e#diff-039cbe711c4af51a6b8aeefc96864f1d3387634f62327fb18489c33c4c6ff7e1)

[Adding fstream to testbench](https://github.com/vishesh32/RISC-V-Team1/commit/4a883e60798b898b1f5c6a94a4c547e49e69d206#diff-997feeff3adda4cd164da68da920683e8039fa54fa0a5f9b7415b386d026bbdc)

[Final data_mem.sv byte addressing fix](https://github.com/vishesh32/RISC-V-Team1/commit/475e0d7ed38c7020f4834b2989b4bd2ea33054cd#diff-039cbe711c4af51a6b8aeefc96864f1d3387634f62327fb18489c33c4c6ff7e1)


This concludes our development of the RISC-V Single cycle processor. The skills I built up in this part of the project assisted me in the next stage of creating the pipelined processor. I found that many similar types of errors were repeated throughout the codebase, and as a result I was much faster at spotting these.

## Pipelined Processor

### Summary of contributions:
- Debugged pipelined processor
- Created testbenches to debug and test modules
- Used Vbuddy to visualise F1 and PDF programs

Half of our team went ahead to begin the creation of the pipelined processor whilst I was debugging the single cycle processor. This allowed us to cover ground and not feel stuck in debugging. Once the initial foundation had been layed I used our high level diagram to confirm that wires had been definied and joined appropriately. 

[Fixing minor code errors quickly due to experience](https://github.com/vishesh32/RISC-V-Team1/commit/e79e2b4de667d5c756442bca5409ffb41e78965d)

[Adding missing logic by comparing to high level diagram](https://github.com/vishesh32/RISC-V-Team1/commit/692c27514057384293e6ac6a3736455910d6f950)

[Thoroughly checking inputs and outputs to avoid errors like the ones made in single cycle](https://github.com/vishesh32/RISC-V-Team1/commit/b3accf69d8ad685b33301ee015646a039b770f75)

Fixing the code didnt feel as tedious now as I knew what I was looking out for, I was also much more comfortable with the SystemVerilog syntax. I felt as if this was really when I was working at a high level and to a standard which assist our team to complete the pipelined processor.

[Adding missing logic](https://github.com/vishesh32/RISC-V-Team1/commit/c1f8316229534b896e11b33aa16f31d23c562a51)

Our control unit had many new additions and so I had to be very careful with checking each pin. At this stage I also organised the order in which we defined the pin connections in the control_top file so that comparing it to the diagram and lower submodules was easier. This sped up the debugging process in the long run.

### High level diagram
![The diagram I used to consolidate our layout](/img/pipelined.jpg)

[Confirming functionality of control_top and editing pipeline registers for clarity](https://github.com/vishesh32/RISC-V-Team1/commit/c41840d489fe9ef51a6e1223e4e0f0403918c99f)

[Confirming ALU functionality and fixing incorrect wiring](https://github.com/vishesh32/RISC-V-Team1/commit/152d4d61bac6b8521d9d7ca36d3e678161bb5e63)

[Removing extra pins which werent necessary](https://github.com/vishesh32/RISC-V-Team1/commit/95705e2d42598a13517b0fd3ca13b5f62e73af1a)


Due to our design choices we commonly had logic as if-else statements in the main section of modules, not within an always_ff or comb block. This meant that I had to refactor all if-else statements into the ternary ? : operator to remove errors whilst keeping the same functionality.

[Replacing if-else constructs with ternary operators](https://github.com/vishesh32/RISC-V-Team1/commit/5058a7b8147cc4feade0f36bc6e0cc53e5c7d119#diff-2a9a7a63d223b4274a102bbb824f596b66dd98f769cf4c557a1213f9b5fdd23e)

By this stage of the project I had figured out how to use gitignore and the testbenching was very similar to the single cycle, although the narrowing of errors was much harder. GTKwave was extremely helpful with a new technique I had learnt to quickly open .vcd files with a .gtkw overlay. 

```
$ gtkwave RISC-V-Team1/pipelined/cpu.vcd -a debug.gtkw

```
This allowed me to always open the vcd file in the same area with the same waveform showing, really speeding up troubleshooting between modifications of our design.

## What I have learned

I have built up a variety of soft skills involving debugging program but also have learnt how to use many new types of software such as GTKwave, Verilator and Git but also become more comfortable with using a Linux environment with bash scripting. This project has had an impact in my general understanding of programming and utilising my own device fully.

In my eyes this is a very important milestone in understanding instruction set architecture and makes me glad I picked EIE. I found myself actually enjoying this task more than any other assignments as it directly correlates to how things are done in reality and in the knowing that the knowledge I have picked up is extremely useful.

One thing to work on in the future would definitely be how we are organised as a team, to maximise our efficiency as I found sometimes we did duplicate tasks or overwrote changes in merges. We could have attempted the further cache challenge if we had used the initial few days to really draw up a plan. After doing this project me and my team understand how long the final stage of testing and debugging actually takes, in the future I will make sure to account for unexpected problems in order to achieve higher.
