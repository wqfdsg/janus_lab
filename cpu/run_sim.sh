# 编译所有文件
verilator --cc --exe --build \
--no-timing \
--top-module tb_top \
alu_ctrl.v alu.v branch_unit.v cpu.v ctrl.v \
dmem.v ex_mem_reg.v forward_unit.v hazard_unit.v \
id_ex_reg.v if_id_reg.v imem.v imm_gen.v \
mem_wb_reg.v pc_reg.v reg_file.v tb_top.v top.v \
sim_main.cpp

# 运行仿真
./obj_dir/Vtb_top