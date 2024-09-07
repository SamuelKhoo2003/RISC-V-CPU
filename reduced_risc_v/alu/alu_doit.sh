#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f red_top.vcd

# run Verilator to translate Verilog into C++, including C++ Testbench
verilator -Wall -Wno-fatal --cc --trace red_top.sv --exe red_top_tb.cpp

# build CPP project via make automatically generaated
make -j -C obj_dir/ -f Vred_top.mk Vred_top

# run exe sim
obj_dir/Vred_top