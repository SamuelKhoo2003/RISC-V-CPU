rm -rf obj_dir
rm -f Vred_top.vcd

verilator --Wall --cc --trace red_top.sv --exe red_top_tb.cpp

make -j -C obj_dir/ -f Vred_top.mk Vred_top

obj_dir/Vred_top