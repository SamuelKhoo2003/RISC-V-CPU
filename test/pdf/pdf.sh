rm -rf obj_dir
rm -f Vcpu.vcd

verilator --Wall --cc --trace cpu.sv --exe cpu_tbpdf.cpp

make -j -C obj_dir/ -f Vcpu.mk Vcpu

obj_dir/Vcpu