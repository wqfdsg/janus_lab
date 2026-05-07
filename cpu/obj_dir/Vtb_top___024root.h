// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_top.h for the primary calling header

#ifndef VERILATED_VTB_TOP___024ROOT_H_
#define VERILATED_VTB_TOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_top__DOT__clk;
        CData/*0:0*/ tb_top__DOT__rst_n;
        CData/*1:0*/ tb_top__DOT__dut__DOT__forward_a;
        CData/*1:0*/ tb_top__DOT__dut__DOT__forward_b;
        CData/*4:0*/ tb_top__DOT__dut__DOT__rd_mem;
        CData/*0:0*/ tb_top__DOT__dut__DOT__reg_write_mem;
        CData/*0:0*/ tb_top__DOT__dut__DOT__mem_read_mem;
        CData/*0:0*/ tb_top__DOT__dut__DOT__mem_write_mem;
        CData/*0:0*/ tb_top__DOT__dut__DOT__mem_to_reg_mem;
        CData/*2:0*/ tb_top__DOT__dut__DOT__func3_mem;
        CData/*4:0*/ tb_top__DOT__dut__DOT__rd_wb;
        CData/*0:0*/ tb_top__DOT__dut__DOT__reg_write_wb;
        CData/*0:0*/ tb_top__DOT__dut__DOT__mem_to_reg_wb;
        CData/*0:0*/ tb_top__DOT__dut__DOT__jump_mem;
        CData/*0:0*/ tb_top__DOT__dut__DOT__jump_wb;
        CData/*0:0*/ tb_top__DOT__dut__DOT__branch_taken;
        CData/*0:0*/ tb_top__DOT__dut__DOT__reg_write_id;
        CData/*0:0*/ tb_top__DOT__dut__DOT__alu_src_id;
        CData/*0:0*/ tb_top__DOT__dut__DOT__mem_read_id;
        CData/*0:0*/ tb_top__DOT__dut__DOT__mem_write_id;
        CData/*0:0*/ tb_top__DOT__dut__DOT__mem_to_reg_id;
        CData/*0:0*/ tb_top__DOT__dut__DOT__branch_id;
        CData/*0:0*/ tb_top__DOT__dut__DOT__jump_id;
        CData/*1:0*/ tb_top__DOT__dut__DOT__alu_op_id;
        CData/*4:0*/ tb_top__DOT__dut__DOT__rd_ex;
        CData/*4:0*/ tb_top__DOT__dut__DOT__rs1_ex;
        CData/*4:0*/ tb_top__DOT__dut__DOT__rs2_ex;
        CData/*2:0*/ tb_top__DOT__dut__DOT__func3_ex;
        CData/*0:0*/ tb_top__DOT__dut__DOT__reg_write_ex;
        CData/*0:0*/ tb_top__DOT__dut__DOT__alu_src_ex;
        CData/*0:0*/ tb_top__DOT__dut__DOT__mem_read_ex;
        CData/*0:0*/ tb_top__DOT__dut__DOT__mem_write_ex;
        CData/*0:0*/ tb_top__DOT__dut__DOT__mem_to_reg_ex;
        CData/*0:0*/ tb_top__DOT__dut__DOT__branch_ex;
        CData/*0:0*/ tb_top__DOT__dut__DOT__jump_ex;
        CData/*1:0*/ tb_top__DOT__dut__DOT__alu_op_ex;
        CData/*3:0*/ tb_top__DOT__dut__DOT__alu_ctrl_ex;
        CData/*0:0*/ tb_top__DOT__dut__DOT__pc_stall;
        CData/*0:0*/ tb_top__DOT__dut__DOT__if_id_stall;
        CData/*0:0*/ tb_top__DOT__dut__DOT__if_id_flush;
        CData/*0:0*/ tb_top__DOT__dut__DOT__id_ex_flush;
        CData/*0:0*/ tb_top__DOT__dut__DOT__hazard_inst__DOT__load_use_hazard;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_top__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_top__DOT__rst_n__0;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ tb_top__DOT__dmem_rdata;
        IData/*31:0*/ tb_top__DOT__i;
        IData/*31:0*/ tb_top__DOT__dut__DOT__alu_result_mem;
        IData/*31:0*/ tb_top__DOT__dut__DOT__rs2_data_mem;
        IData/*31:0*/ tb_top__DOT__dut__DOT__alu_result_wb;
        IData/*31:0*/ tb_top__DOT__dut__DOT__mem_data_wb;
        IData/*31:0*/ tb_top__DOT__dut__DOT__wb_data;
        IData/*31:0*/ tb_top__DOT__dut__DOT__pc_plus4_mem;
        IData/*31:0*/ tb_top__DOT__dut__DOT__pc_plus4_wb;
        IData/*31:0*/ tb_top__DOT__dut__DOT__rs2_forwarded;
        IData/*31:0*/ tb_top__DOT__dut__DOT__pc_if;
        IData/*31:0*/ tb_top__DOT__dut__DOT__pc_next_if;
        IData/*31:0*/ tb_top__DOT__dut__DOT__branch_target;
        IData/*31:0*/ tb_top__DOT__dut__DOT__instr_ex;
        IData/*31:0*/ tb_top__DOT__dut__DOT__pc_id;
        IData/*31:0*/ tb_top__DOT__dut__DOT__pc_plus4_id;
        IData/*31:0*/ tb_top__DOT__dut__DOT__instr_id;
        IData/*31:0*/ tb_top__DOT__dut__DOT__imm_id;
    };
    struct {
        IData/*31:0*/ tb_top__DOT__dut__DOT__pc_ex;
        IData/*31:0*/ tb_top__DOT__dut__DOT__pc_plus4_ex;
        IData/*31:0*/ tb_top__DOT__dut__DOT__imm_ex;
        IData/*31:0*/ tb_top__DOT__dut__DOT__rs1_data_ex;
        IData/*31:0*/ tb_top__DOT__dut__DOT__rs2_data_ex;
        IData/*31:0*/ tb_top__DOT__dut__DOT__alu_a_ex;
        IData/*31:0*/ tb_top__DOT__dut__DOT__alu_b_ex;
        IData/*31:0*/ tb_top__DOT__dut__DOT__alu_result_ex;
        IData/*31:0*/ tb_top__DOT__dut__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ __Vdly__tb_top__DOT__dut__DOT__instr_id;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 1024> tb_top__DOT__imem;
        VlUnpacked<CData/*7:0*/, 4096> tb_top__DOT__dmem;
        VlUnpacked<IData/*31:0*/, 32> tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_top___024root(Vtb_top__Syms* symsp, const char* v__name);
    ~Vtb_top___024root();
    VL_UNCOPYABLE(Vtb_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
