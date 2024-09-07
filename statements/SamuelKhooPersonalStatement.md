# Samuel Khoo Ing Shin Personal Statement 

### Overview Of My Contributions
Within the **single cycle** I contributed primarily to the program counter, data memory and instruction memory files, with further work on debugging and organising files, as well as connecting components together. 
In the **pipelining** section of the project, I worked on writing a new aludecoder and a new maindecoder, as well as working to create top files to connect everything together. Aside from this I also worked on developing and debugging the pipelining registers and the hazard unit. 

### Structure
Below are hyperlinks which relate to the different sections within my personal statement. 
- [Single Cycle CPU](#single-cycle-processor)
- [Pipelined CPU](#pipelining)
- [Conclusions and Evaluation](#conclusions-and-evaluations)

## Single Cycle Processor

### Introduction
Within this part of the project, I primarily focused on the development of the PC as well as debugging of the control unit and adding some features to the ALU module. I also created some general components/modules that could be reused and implemented across our architecture.

Although individual components within the processor were completed relatively quickly, joining all the components and ensuring full functionality was a much longer task than the team had predicted. 

### Program Counter
To successfully complete and attain an operational PC I broke the counter into 3 seperate sections, a mux section, a register section and a top file controlling the component. I would later also write 2 general muxes one that had 2 inputs and another with 4 inputs, this would prove to be more useful in further developmement stages. I also worked closely with Anson and Bruno to debug certain elements that stemmed from the outputs of the Program Counter (e.g. the Control Unit). 
The changes and features I added to form the Program Counter module are shown below:
- [Created PC top file](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/680b3133db627e28b6332913bc3934294a990023)
- [Completion of PC mux and PC register file](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/dfefd5fbc303c96fe067b5b86232d1488d5fb6aa)
- [Debugging the PC module](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/bf0a24d7fd1cc6c92495adb22617d6088012e06e)
- [Testing files for PC](https://github.com/chinjyanson/Reduced_RISC-V-Team1/commit/63e483c91df0967193e24b5b6fc0154ee0763f18)

// Miscellaneous related to PC //
Following this I worked closely with Bruno to ensure the jump instructions were functional and to incorporate instructions which involved manipulating the counter value. One change we implemented was increasing the bit width of PCSrc, this required the implementation of a wider mux and led me to write a mux4 module. 
- [Added a wider mux](https://github.com/vishesh32/RISC-V-Team1/commit/e4f736baa8a2161ccc964539c5579da8ea125249)
- [Restyled 4 wide mux](https://github.com/vishesh32/RISC-V-Team1/commit/a3e41d75a6b363352552fe89601aed3e12cb286c)
I would then later realise that there were certain instances which made use of a 3 out of 4 inputs which would throw a warning upon compiling, this led me to write a mux3 module which would eliminate this error. 
- [Creation of mux3 component](https://github.com/vishesh32/RISC-V-Team1/commit/99e79496ac7c7b38bb8392587c055d3ff82930e8)
The code below shows the implementation of a dont care case to avoid errors:
```
always_comb begin
    case (control)
        2'b00: out = input0;
        2'b01: out = input1;
        2'b10: out = input2;
        default: out = 32'hx; // Default case (don't care case)
    endcase
end
```
This was then used within the PC top module as shown below: 
```
mux3 pc_mux(
    .control    (PCSrc_i),
    .input0     (PCPlus4F_o),
    .input1     (PCTarget_i),
    .input2     (ALUResultE_i),
    .out        (next_PC)
);

```
### Data Mem
Following the completion of the PC module, I was rotated onto working on the data memory module which primarly handled write instructions of different length and storing data. This was initially relatively confusing and I worked with Bruno to develop this module to match the existing instruction codes. 
- [First draft of the datamem file](https://github.com/vishesh32/RISC-V-Team1/commit/58a03747ecc7961354f11ed2454cb3b9907342db)
- [Implementing different load instructions](https://github.com/vishesh32/RISC-V-Team1/commit/c389c01ad1b840522539c9a7e5a7b442de2bff70)
Throughout the pipeline development process, I would realise that this implementation would cause errors where incorrect data was being sent and fed back to the register file. This would be debugged by both myself and Bruno. The updated version of the data mem would include a 2 bit wide Write Enable/MemWrite (which is needed to differentiate between the different load instructions). This is shown in the code snippet below:
```
always_ff @(posedge clk) begin
    case(WE) // this could be done cleaner
    2'b01: 
    begin //word write
        data_mem_register[add] <= WD[7:0];
        data_mem_register[add+1] <= WD[15:8];
        data_mem_register[add+2] <= WD[23:16];
        data_mem_register[add+3] <= WD[31:24];
    end
    2'b11:
    begin //write byte
        data_mem_register[A] <=  WD[7:0];
    end
    default: data_mem_register[A] <= data_mem_register[A];
    endcase
end
```

### Register File and Instruction Mem
For these components, I worked closely with their creators to refine certain parts and modified their styling to ensure ease of understand. Bruno and I also ensured that these components would be functional with our control unit and data memory. This involved changing the clock detecting edge to be negative on our register file (read and write on different edges) and reorganising logic as seen in the commit and code snippet below:
- [Reorganised regfile.sv](https://github.com/vishesh32/RISC-V-Team1/commit/0eff28f042d5ece8a8a160522d1007df79a89b40)
```
always @(negedge clk) begin
    if (A3 != 0) begin
        case (WE3)
            3'b001: reg_array[A3] <= WD3; // write
            3'b010: reg_array[A3] <= {{16{WD3[15]}}, WD3[15:0]}; // lh - sign extend
            3'b011: reg_array[A3] <= {{24{WD3[7]}}, WD3[7:0]}; // lb - sign extend
            3'b111: reg_array[A3] <= {{24'b0}, WD3[7:0]};   //  lbu - zero extend
            3'b110: reg_array[A3] <= {16'b0, WD3[15:0]}; // lhu - zero extend
            default: reg_array[A3] <= reg_array[A3];
        endcase
    end
```

For instruction mem, there were fewer changes compared to the reduced RISC-V processor. I mainly rewrote the parameters and modified the input and output logic as well as the size of the array. I had originally directly assigned the instruction output to be an address in the rom array, however, after discussing with Bruno, we came to the conclusion of implementing a single assign instruction to account for all 4 different parts (this is best demonstrated in the code snippet below)
- [New instruction mem](https://github.com/vishesh32/RISC-V-Team1/commit/e31e78940a98fd20bc7fe8a1b3df8d07b401541e)
```
logic [ADDRESS_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];
// this is the core idea of splitting into 4, 8 bit width parts
assign Instr_o = {{rom_array[addr_i+3]}, {rom_array[addr_i+2]}, {rom_array[addr_i+1]}, {rom_array[addr_i]}};
```

### Debugging
Throughout the development of the single cycle CPU, I also made numerous bug fixes and a plethora of reorganisation. This included adding in functional branch logic, fixing ALU instructions, ensuring that the right opcodes corresponded with the right instructions and similar alternatives. During the debugging process, I worked both Vishesh and Anson to review error messages and warning thrown as well as inspecting the GTKWave sheets to trace the data in registers and different wires. Evidence demonstrating this is hyperlinked below:
- [Debugging sizing error in regfile](https://github.com/vishesh32/RISC-V-Team1/commit/5ff7372e4a08abd6bcdda4dd846755f4b275f957)
- [Debugging negedge clock in regfile](https://github.com/vishesh32/RISC-V-Team1/commit/ad2adb8537f4c680262bcc5aa0e0e75868ada94b)
- [Debugging lui instruction](https://github.com/vishesh32/RISC-V-Team1/commit/9a23e9b43b975b82262243949680b0667e7a6d99)
- [Debugging the ImmSrc to 3 wide](https://github.com/vishesh32/RISC-V-Team1/commit/e4497dfd35dd1d1710fb21b7332aa8ea9c254514)
- [Fixed misdeclaration of bits](https://github.com/vishesh32/RISC-V-Team1/commit/1731b61a9ade405087ab320799c796d4e8933eef)
- [Further debugging of R-type instructions](https://github.com/vishesh32/RISC-V-Team1/commit/8cfc5f7b21506f4a5561cdc0dcf4e22912592ebb)


## Pipelining
The core concept of our pipelined cpu developed upon our existing single cycle with the use of the architecture diagram provided within Lecture 8 (Pipelining) and information found within the Sarah Harris and David Harris textbook, these were used as reference but not directly copied. We then added modifications to their designs and made some changes to our components to take into account factors like loading half the word, loading the last 8 bits and different lengths of storing words. The images whichwe used as reference are shown below:

![Lecture 8 Pipelining Diagram](/img//pipelined.jpg)
- The pipeline registers seem to combine both control unit and data path pipelining registers, I decided to split them up but retain the same clk cycle/signal to ensure that they work in time. This is to reduce the confusion of having a large number of different inputs and outputs for each pipeline register. 

![Sarah Harris and David Harris Textbook](/img//textbook.jpg)
- You can see the new hazard unit signals that were missing in the architecture/diagram given in the original lecture. 

I reworked many components within this section of our project as we realised that there were certain errors and misorganisation within our single cycle that would hinder our pipelined development, I worked closely with Bruno to create pipelining registers and ensured that we were able to achieve hazard handling. Building upon Bruno's initial pipelining ideas, I took the initiative to split the pipelining registers into control unit and datapath pipeline registers, this would allow for clarity and ease of modification. This is shown in the code sample and commits below:
- [Example of a control unit pipeline register](https://github.com/vishesh32/RISC-V-Team1/commit/a29efa27d9dcdf7a0953806c3e3b9c14ae40f641)
- [Example of a data path pipeline register](https://github.com/vishesh32/RISC-V-Team1/commit/81214bc940dbf3314fa11de5b38f1f9a238df7b3)
- [Controller top module](https://github.com/vishesh32/RISC-V-Team1/commit/bead218ee0735f435d95a3c69ae8dc6be4eb9044)
- [Top RISCV file draft](https://github.com/vishesh32/RISC-V-Team1/commit/bd0264c0bc639c614dfc2eb1adbea6710c489caf)

The simplified top level control file made it much simpler to trace the different logics and control unit pipelining registers, I also made a tentative draft for the implementation of a pipelining in our datapath, however, we chose not to fully implement this design as we felt that it would be relatively difficult to debug and could be a source of small errors that were difficult to spot. Instead we took some ideas of splitting the components chronologically and multideclaration of logic and used these within our final design. 
- [Draft top datapath with pipeline registers](https://github.com/vishesh32/RISC-V-Team1/commit/104245d1ebe89f35dd544b5c80f983f610b8b9cc)

All the components mentioned above were then modified to varying extents to suit the extra signals and implemented as submodules in larger files during our debugging and testing process. I also worked with Anson and Bruno to create a hazard unit draft, this was then broken down by Bruno into further sub modules to trace and debug however, the overall logic and signals still remain the same. 
- [New hazard unit draft](https://github.com/vishesh32/RISC-V-Team1/commit/1887fae085c100c83dc7e0fd9ec2c8d7ff8e5062)

```
// if ((RegWriteM!= 3'b0)||(RegWriteW!= 3'b0))begin
//     if(Rs1E == RdM) 
//         FowardAE = 2'b10;
//     else 
//         FowardAE = (Rs1E == RdW) ? 2'b01 : 2'b00;
    

//     //FowardBE
//     if(Rs2E == RdM) 
//         FowardBE = 2'b10;
//     else 
//         FowardBE = (Rs2E == RdW) ? 2'b01 : 2'b00;
    
// end else begin
//     FowardAE = 2'b00;
//     FowardBE = 2'b00;
// end
```
Above we have a now commented out piece of code which has been rewritten more efficiently, but this handles the forwarding signals which control the hazard handling 3 wide muxes.

Aside from this, I made changes to the control unit from the single cycle, the control unit had previously combined the aludecoder and the main decoder together, making it difficult to debug and sometimes hard to trace errors. To resolve this, I wrote split both decoders up and created a new controller (top control file). This was well received by all members within my team and I felt that it made it much easier to trace any errors and make changes. The changes made are shown below:
- [New ALU decoder](https://github.com/vishesh32/RISC-V-Team1/commit/5cf3805eaf8e07d5949559ae43988e8240070f33)
Shown below is the final ALU decoder used within our design, one of the key things to note is the addition of ALUOp being 2'b11 for lui, this was added because we realised that we needed a way to unique detect and assign 3'b111 for the lui instruction and I had realised on 3 out of 4 of the ALUOp instructions were being used, hence, I decided that it was possible to make use of the 2'b11 case for the lui instruction. 
```
case (ALUOp)
    2'b00: ALUControl = 3'b000; // addition
    2'b01: ALUControl = 3'b001; // subtraction
    2'b11: ALUControl = 3'b111; // set for the lui instruction
    default: // made it a default but in theory just ALUOp = 2'b10
        case (funct3)
            3'b000: ALUControl = (RtypeSub) ? 3'b001 : 3'b000; // takes into account case where RtypeSub gives add or addi or sub
            3'b001: ALUControl = 3'b101; // ssl, slli 
            // 3'b010: ALUControl = 3'b101; // set less than (ended up not being used)
            3'b110: ALUControl = 3'b011; // or
            3'b111: ALUControl = 3'b010; // and 
            default: ALUControl = 3'bxxx;
        endcase
```

- [New Main decoder](https://github.com/vishesh32/RISC-V-Team1/commit/66650eb3dd9e239fbbbfe08e9f8c900d1ed16726)
Within this module I decides to reduce the complexity by having large multi one line assignment. The core idea was instead of having numerous assignments for each opcode that would be long and tedious, I would just assign them all in one line, splitting the bit values/signal values up with an _ this would allow for swift changing of any values, accelerating the debugging process and it would made it easier to trace/follow. This would then be assigned to the values using the following assign command:  ``` assign {RegWrite, ResultSrc, MemWrite, Jump, Branch, ALUSrc, ImmSrc, ALUOp} = controls; ``` This concept was later further developed by both Bruno and myself to split the load and store instructions to have specific controls and 3 bit wide regwrites or memwrites which could control their respective components to ensure that the correct instruction was performed. The code snippet below demonstrates the multi assignment all in 1 line. 
```
case (op)
    // RegWrite_ResultSrc_MemWrite_Jump_Branch_ALUSrc_ImmSrc_ALUOp
    7'b0000011:begin
        controls = 13'b1_01_00_0_0_1_000_00; // lw (default to lw)
        case(funct3)
            3'b100: controls = 14'b1_01_10_0_0_1_000_00 ; //lbu
            default: controls = controls; 
        endcase
    end

    // store instructions were here
    
    7'b0110011: controls = 13'b1_00_00_0_0_0_xxx_10; // R-type
    7'b1100011: controls = 13'b0_00_00_0_1_0_010_01; // B-type (beq) - why does ALUOp have to be 01? - that goes into substraction
    7'b0010011: controls = 13'b1_00_00_0_0_1_000_10; // I-type (ALUSrc is 1 - double check)
    7'b0110111: controls = 13'b1_00_00_0_0_1_100_11; // lui (ALUOp used to be 00 but now set to 11)
    7'b1101111: controls = 13'b1_10_00_1_0_0_011_00; // jal - changed jump to 0 and branch to 1
    7'b1100111: controls = 13'b1_10_00_1_0_1_000_00; // jalr
    7'b0000000: controls = 13'b0_00_00_0_0_0_000_00; // for default values on reset
    default: controls = 13'bx_xx_xx_x_x_x_xxx_xx; // instr not implemented
endcase
```

- [Final Versions of Decoders](https://github.com/vishesh32/RISC-V-Team1/commit/52f900875a3972f0b533fa75009af298a702f29c)
- [Control unit working with decoders](https://github.com/vishesh32/RISC-V-Team1/commit/ac0f60d0a88b4e21338ea48971ad2e648419253b)


One of the key references which I referred to outside of the files which had been previously written by Bruno was the slides from Lecture 7 which is shown here:
![Lecture 7 Decoder Slide](/img//breakdownofdecoder.png)
![Aludecoder Inspiration](/img//aludecoder.png)
![Maindecoder Inspiration](/img//maindecoder.png)

I would also extensively work upon developing the draft of the top level control unit file and other top level files in conjuction with Bruno to implement extra logic I had missed and to reduce the need for further muxes and extra unnecessary signals which would complicate the existing design. One implementation which I wrote independently was to detect the difference between a JAL and JALR and also to flip the Zero bit if the input given was a BNE instruction for a branch instruction. This is shown in the code snippet below: 
```
assign ZeroOp = ZeroE_i ^ funct3E[0]; // flip the Zero input if BNE

always_comb
    if (JumpE)      PCSrcE_o = ALUSrcE_o ? 2'b10: 2'b01 ; //choose between JAL and JALR without extra logic
    else PCSrcE_o = (BranchE & ZeroOp) ? 2'b01 : 2'b00;

```
This is just one of the numerous other changes which I made to reduce the need for extra logic and to simplify the design to allow for a functional pipelining. These components were then verified by Vishesh who worked primarily in testing as well as via analysing GTKWave graphs with Bruno. 

### Restyling/Miscellanous Developement
A large portion of my contribtions were also on miscellanous components with minor changes on port widths, restyling for clarity, organising files for ease of tracing and including different comments to explain the function of a module to allow for other members to easily understand the function of the module. This including adding the _i and _o to the input and output ports of different modules as well as formatting the port and parameter sections of a module to achieve a unified style across our CPU. Some examples of this are shown below: 
- [Example of restyling](https://github.com/vishesh32/RISC-V-Team1/commit/46032425739ae6ab26cd36ac6bdc4f3a326db596)
- [Example of reformatting](https://github.com/vishesh32/RISC-V-Team1/commit/a80cd1f020f241408510ee485a1c847a923b5a53)
- [Example of adding comments for clarity](https://github.com/vishesh32/RISC-V-Team1/commit/7548caf7ad57d462d3724947a5455a391613a72f)
- [Example of adding _o and _ i](https://github.com/vishesh32/RISC-V-Team1/commit/5d87ec413f5d2de9ceaeb800607fa378e7a1708d)
- [Example of reorganising files to prevent confusion](https://github.com/vishesh32/RISC-V-Team1/commit/d037ae67f569aeab43d1283df92efbab34b2f7ba)
The changes were well received within my team and led to an improved workflow by reducing confusion and the time taken to search for variables and files. The new styling and formatting of the System Verilog files were intended to match those of industry standard and keep the project as professional as possible. 


### Conclusions and Evaluations

## Review
All in all this project was an eye opening experience for me, being my first collaborative software project that involved more than 2 members, I discovered the difficulties when working in a large team in terms of coordination. This eventually developed over time and I believe that the overall team dynamic greatly improved towards the final stages of our project. 

There were numerous times where incorrect naming of input and output ports and inconsistent declaration of port widths caused confusing errors and warnings which led to hours of debugging. Nevertheless, being able to recognise these errors and make the correct changes to finally see the desired output was highly fulfilling. 

Learning to organise my verilog files and write them in a style which is easily understood by my teammates to allow for ease of debugging was also a new skill which I developed throughout this project. I enjoyed the continuous development of the CPU, focusing on the completion of single cycle, followed by implementations of pipelining which then evolved into completed hazard handling with pipelining. This "growth" of our CPU was interesting to see and I enjoyed seeing the different components change and discussing different implementations of modules to allow for the completion of each stage. 

Through this project, I feel that my understand of the RISC-V cpu has greatly deepened and I now have a degree of confidence in writing System Verilog files and analysing CPU designs and logic. Aside from this learning more about correctly detailing my git commits was also important for future collaborative projects and further developed upon my existing knowledge from personal and past group projects. Additionally learning to document my files and explaining my System Verilog files and attmepting to join my modules with other members taught me to efficiently converse my ideas and break down complex components to avoid being overwhelmed. 

Lastly learning to communicate and plan as a team was vital and I definitely saw this aspect of the project growing greatly for all members within the team as we understood each others work flow and worked on more problems together. 

To conclude, this project was a unique learning experience where I gained profound insight into the material covered in lectures and built upon the skills from the previous labs I had completed. The networking and collaborative skills I developed within this project will also be valuable in future endeavours and projects. 

## What I Would Change
If I was to undertake this project again, I would definitely have planned the outline and developments of modules before splitting up the components for seperate members. This would have saved us a large amount of time involved in rewriting components from single cycle to pipeline where our implementation was previously correct but almost impossible to pipeline efficiently. 

Aside from this, I would have definitely tried to establish a clear structure and Verilog file style with a clear file and port naming to prevent confusion upon joining the modules together. This was also another aspect within our project that led to confusion and time wasted debugging minor errors. 

I would also focus on being more proactive in engaging in communication with my teammates early within the project, as early on in the project I often spent a large amount of time trying to understand the files written by my other teammates insteads of directly taking the initiative to contact them to explain and debug a problem with me. This greatly changed during the second part of our project and had a notable impact on the efficiency of debugging problems and achieving a successful result. 

Ultimately, I would have definitely completed more research into components and using the resources available to us online to develop the RISC-V CPU instead of attempting to create my own protocol and modules from scratch without a reference. We did make use of a textbook and resources noted by other groups to our advantage towards the end of our project but I felt that this was discovered a little late. 