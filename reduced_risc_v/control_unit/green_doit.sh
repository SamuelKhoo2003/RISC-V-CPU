rm -rf obj_dir
rm -f Vgreen.vcd

verilator --Wall --cc --trace green.sv --exe green_tb.cpp

make -j -C obj_dir/ -f Vgreen.mk Vgreen

obj_dir/Vgreen