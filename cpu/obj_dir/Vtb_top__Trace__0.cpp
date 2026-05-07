// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_top__Syms.h"


void Vtb_top___024root__trace_chg_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_chg_0\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_top___024root__trace_chg_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->tb_top__DOT__dut__DOT__pc_if),32);
        bufp->chgBit(oldp+1,(vlSelf->tb_top__DOT__dut__DOT__mem_read_mem));
        bufp->chgCData(oldp+2,(vlSelf->tb_top__DOT__dut__DOT__forward_a),2);
        bufp->chgCData(oldp+3,(vlSelf->tb_top__DOT__dut__DOT__forward_b),2);
        bufp->chgCData(oldp+4,(vlSelf->tb_top__DOT__dut__DOT__rd_mem),5);
        bufp->chgBit(oldp+5,(vlSelf->tb_top__DOT__dut__DOT__reg_write_mem));
        bufp->chgBit(oldp+6,(vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_mem));
        bufp->chgIData(oldp+7,(vlSelf->tb_top__DOT__dut__DOT__alu_result_wb),32);
        bufp->chgIData(oldp+8,(vlSelf->tb_top__DOT__dut__DOT__mem_data_wb),32);
        bufp->chgCData(oldp+9,(vlSelf->tb_top__DOT__dut__DOT__rd_wb),5);
        bufp->chgBit(oldp+10,(vlSelf->tb_top__DOT__dut__DOT__reg_write_wb));
        bufp->chgBit(oldp+11,(vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_wb));
        bufp->chgIData(oldp+12,(vlSelf->tb_top__DOT__dut__DOT__wb_data),32);
        bufp->chgIData(oldp+13,(vlSelf->tb_top__DOT__dut__DOT__pc_plus4_mem),32);
        bufp->chgIData(oldp+14,(vlSelf->tb_top__DOT__dut__DOT__pc_plus4_wb),32);
        bufp->chgBit(oldp+15,(vlSelf->tb_top__DOT__dut__DOT__jump_mem));
        bufp->chgBit(oldp+16,(vlSelf->tb_top__DOT__dut__DOT__jump_wb));
        bufp->chgCData(oldp+17,((0x7fU & vlSelf->tb_top__DOT__dut__DOT__instr_ex)),7);
        bufp->chgIData(oldp+18,(((IData)(4U) + vlSelf->tb_top__DOT__dut__DOT__pc_if)),32);
        bufp->chgBit(oldp+19,(vlSelf->tb_top__DOT__dut__DOT__jump_ex));
        bufp->chgIData(oldp+20,(vlSelf->tb_top__DOT__dut__DOT__branch_target),32);
        bufp->chgIData(oldp+21,(vlSelf->tb_top__DOT__dut__DOT__instr_ex),32);
        bufp->chgIData(oldp+22,(vlSelf->tb_top__DOT__dut__DOT__pc_id),32);
        bufp->chgIData(oldp+23,(vlSelf->tb_top__DOT__dut__DOT__pc_plus4_id),32);
        bufp->chgIData(oldp+24,(vlSelf->tb_top__DOT__dut__DOT__pc_ex),32);
        bufp->chgIData(oldp+25,(vlSelf->tb_top__DOT__dut__DOT__pc_plus4_ex),32);
        bufp->chgIData(oldp+26,(vlSelf->tb_top__DOT__dut__DOT__imm_ex),32);
        bufp->chgIData(oldp+27,(vlSelf->tb_top__DOT__dut__DOT__rs1_data_ex),32);
        bufp->chgIData(oldp+28,(vlSelf->tb_top__DOT__dut__DOT__rs2_data_ex),32);
        bufp->chgCData(oldp+29,(vlSelf->tb_top__DOT__dut__DOT__rd_ex),5);
        bufp->chgCData(oldp+30,(vlSelf->tb_top__DOT__dut__DOT__rs1_ex),5);
        bufp->chgCData(oldp+31,(vlSelf->tb_top__DOT__dut__DOT__rs2_ex),5);
        bufp->chgBit(oldp+32,(vlSelf->tb_top__DOT__dut__DOT__reg_write_ex));
        bufp->chgBit(oldp+33,(vlSelf->tb_top__DOT__dut__DOT__alu_src_ex));
        bufp->chgBit(oldp+34,(vlSelf->tb_top__DOT__dut__DOT__mem_read_ex));
        bufp->chgBit(oldp+35,(vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_ex));
        bufp->chgBit(oldp+36,(vlSelf->tb_top__DOT__dut__DOT__branch_ex));
        bufp->chgCData(oldp+37,(vlSelf->tb_top__DOT__dut__DOT__alu_op_ex),2);
        bufp->chgCData(oldp+38,(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex),4);
        bufp->chgCData(oldp+39,((7U & (vlSelf->tb_top__DOT__dut__DOT__instr_ex 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+40,((vlSelf->tb_top__DOT__dut__DOT__instr_ex 
                                 >> 0x19U)),7);
        bufp->chgIData(oldp+41,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0]),32);
        bufp->chgIData(oldp+42,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[1]),32);
        bufp->chgIData(oldp+43,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[2]),32);
        bufp->chgIData(oldp+44,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[3]),32);
        bufp->chgIData(oldp+45,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[4]),32);
        bufp->chgIData(oldp+46,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[5]),32);
        bufp->chgIData(oldp+47,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[6]),32);
        bufp->chgIData(oldp+48,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[7]),32);
        bufp->chgIData(oldp+49,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[8]),32);
        bufp->chgIData(oldp+50,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[9]),32);
        bufp->chgIData(oldp+51,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[10]),32);
        bufp->chgIData(oldp+52,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[11]),32);
        bufp->chgIData(oldp+53,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[12]),32);
        bufp->chgIData(oldp+54,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[13]),32);
        bufp->chgIData(oldp+55,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[14]),32);
        bufp->chgIData(oldp+56,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[15]),32);
        bufp->chgIData(oldp+57,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[16]),32);
        bufp->chgIData(oldp+58,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[17]),32);
        bufp->chgIData(oldp+59,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[18]),32);
        bufp->chgIData(oldp+60,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[19]),32);
        bufp->chgIData(oldp+61,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[20]),32);
        bufp->chgIData(oldp+62,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[21]),32);
        bufp->chgIData(oldp+63,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[22]),32);
        bufp->chgIData(oldp+64,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[23]),32);
        bufp->chgIData(oldp+65,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[24]),32);
        bufp->chgIData(oldp+66,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[25]),32);
        bufp->chgIData(oldp+67,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[26]),32);
        bufp->chgIData(oldp+68,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[27]),32);
        bufp->chgIData(oldp+69,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[28]),32);
        bufp->chgIData(oldp+70,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[29]),32);
        bufp->chgIData(oldp+71,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[30]),32);
        bufp->chgIData(oldp+72,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[31]),32);
        bufp->chgIData(oldp+73,(vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+74,(((IData)(vlSelf->tb_top__DOT__dut__DOT__jump_ex)
                                  ? ((0x6fU == (0x7fU 
                                                & vlSelf->tb_top__DOT__dut__DOT__instr_ex))
                                      ? vlSelf->tb_top__DOT__dut__DOT__branch_target
                                      : (0xfffffffeU 
                                         & vlSelf->tb_top__DOT__dut__DOT__alu_result_ex))
                                  : ((IData)(vlSelf->tb_top__DOT__dut__DOT__branch_taken)
                                      ? vlSelf->tb_top__DOT__dut__DOT__branch_target
                                      : ((IData)(4U) 
                                         + vlSelf->tb_top__DOT__dut__DOT__pc_if)))),32);
        bufp->chgIData(oldp+75,(((0x6fU == (0x7fU & vlSelf->tb_top__DOT__dut__DOT__instr_ex))
                                  ? vlSelf->tb_top__DOT__dut__DOT__branch_target
                                  : (0xfffffffeU & vlSelf->tb_top__DOT__dut__DOT__alu_result_ex))),32);
        bufp->chgIData(oldp+76,(((0U == (0x1fU & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                  >> 0xfU)))
                                  ? 0U : (((IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_wb) 
                                           & ((0x1fU 
                                               & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                  >> 0xfU)) 
                                              == (IData)(vlSelf->tb_top__DOT__dut__DOT__rd_wb)))
                                           ? vlSelf->tb_top__DOT__dut__DOT__wb_data
                                           : vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs
                                          [(0x1fU & 
                                            (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                             >> 0xfU))]))),32);
        bufp->chgIData(oldp+77,(((0U == (0x1fU & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                  >> 0x14U)))
                                  ? 0U : (((IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_wb) 
                                           & ((0x1fU 
                                               & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                  >> 0x14U)) 
                                              == (IData)(vlSelf->tb_top__DOT__dut__DOT__rd_wb)))
                                           ? vlSelf->tb_top__DOT__dut__DOT__wb_data
                                           : vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs
                                          [(0x1fU & 
                                            (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                             >> 0x14U))]))),32);
        bufp->chgBit(oldp+78,(((8U == (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex)) 
                               & VL_LTS_III(32, vlSelf->tb_top__DOT__dut__DOT__alu_a_ex, vlSelf->tb_top__DOT__dut__DOT__alu_b_ex))));
        bufp->chgBit(oldp+79,(((9U == (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex)) 
                               & (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                  < vlSelf->tb_top__DOT__dut__DOT__alu_b_ex))));
        bufp->chgBit(oldp+80,(((IData)(vlSelf->tb_top__DOT__dut__DOT__branch_ex) 
                               & ((4U & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                   ? ((2U & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                       ? ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                           ? (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                              >= vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)
                                           : (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                              < vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded))
                                       : ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                           ? VL_GTES_III(32, vlSelf->tb_top__DOT__dut__DOT__alu_a_ex, vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)
                                           : VL_LTS_III(32, vlSelf->tb_top__DOT__dut__DOT__alu_a_ex, vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)))
                                   : ((1U & (~ ((IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex) 
                                                >> 1U))) 
                                      && ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                           ? (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                              != vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)
                                           : (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                              == vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)))))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+81,(vlSelf->tb_top__DOT__dut__DOT__alu_result_mem),32);
        bufp->chgIData(oldp+82,(vlSelf->tb_top__DOT__dut__DOT__rs2_data_mem),32);
        bufp->chgBit(oldp+83,(vlSelf->tb_top__DOT__dut__DOT__mem_write_mem));
        bufp->chgCData(oldp+84,(vlSelf->tb_top__DOT__dut__DOT__func3_mem),3);
        bufp->chgBit(oldp+85,(vlSelf->tb_top__DOT__dut__DOT__pc_stall));
        bufp->chgBit(oldp+86,(vlSelf->tb_top__DOT__dut__DOT__if_id_flush));
        bufp->chgBit(oldp+87,(vlSelf->tb_top__DOT__dut__DOT__id_ex_flush));
        bufp->chgIData(oldp+88,(vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded),32);
        bufp->chgBit(oldp+89,(vlSelf->tb_top__DOT__dut__DOT__branch_taken));
        bufp->chgIData(oldp+90,(vlSelf->tb_top__DOT__dut__DOT__instr_id),32);
        bufp->chgCData(oldp+91,((0x1fU & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+92,((0x1fU & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+93,((0x1fU & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                          >> 7U))),5);
        bufp->chgCData(oldp+94,((7U & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+95,((0x7fU & vlSelf->tb_top__DOT__dut__DOT__instr_id)),7);
        bufp->chgBit(oldp+96,(vlSelf->tb_top__DOT__dut__DOT__reg_write_id));
        bufp->chgBit(oldp+97,(vlSelf->tb_top__DOT__dut__DOT__alu_src_id));
        bufp->chgBit(oldp+98,(vlSelf->tb_top__DOT__dut__DOT__mem_read_id));
        bufp->chgBit(oldp+99,(vlSelf->tb_top__DOT__dut__DOT__mem_write_id));
        bufp->chgBit(oldp+100,(vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_id));
        bufp->chgBit(oldp+101,(vlSelf->tb_top__DOT__dut__DOT__branch_id));
        bufp->chgBit(oldp+102,(vlSelf->tb_top__DOT__dut__DOT__jump_id));
        bufp->chgCData(oldp+103,(vlSelf->tb_top__DOT__dut__DOT__alu_op_id),2);
        bufp->chgIData(oldp+104,(vlSelf->tb_top__DOT__dut__DOT__imm_id),32);
        bufp->chgCData(oldp+105,(vlSelf->tb_top__DOT__dut__DOT__func3_ex),3);
        bufp->chgBit(oldp+106,(vlSelf->tb_top__DOT__dut__DOT__mem_write_ex));
        bufp->chgIData(oldp+107,(vlSelf->tb_top__DOT__dut__DOT__alu_a_ex),32);
        bufp->chgIData(oldp+108,(vlSelf->tb_top__DOT__dut__DOT__alu_b_ex),32);
        bufp->chgIData(oldp+109,(vlSelf->tb_top__DOT__dut__DOT__alu_result_ex),32);
        bufp->chgBit(oldp+110,((0U == vlSelf->tb_top__DOT__dut__DOT__alu_result_ex)));
        bufp->chgBit(oldp+111,(vlSelf->tb_top__DOT__dut__DOT__if_id_stall));
        bufp->chgBit(oldp+112,(((4U & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                 ? ((2U & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                     ? ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                         ? (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                            >= vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)
                                         : (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                            < vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded))
                                     : ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                         ? VL_GTES_III(32, vlSelf->tb_top__DOT__dut__DOT__alu_a_ex, vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)
                                         : VL_LTS_III(32, vlSelf->tb_top__DOT__dut__DOT__alu_a_ex, vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)))
                                 : ((1U & (~ ((IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex) 
                                              >> 1U))) 
                                    && ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                         ? (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                            != vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)
                                         : (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                            == vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded))))));
        bufp->chgBit(oldp+113,(vlSelf->tb_top__DOT__dut__DOT__hazard_inst__DOT__load_use_hazard));
    }
    bufp->chgBit(oldp+114,(vlSelf->tb_top__DOT__clk));
    bufp->chgBit(oldp+115,(vlSelf->tb_top__DOT__rst_n));
    bufp->chgIData(oldp+116,(vlSelf->tb_top__DOT__imem
                             [(0x3ffU & (vlSelf->tb_top__DOT__dut__DOT__pc_if 
                                         >> 2U))]),32);
    bufp->chgIData(oldp+117,(vlSelf->tb_top__DOT__dmem_rdata),32);
    bufp->chgIData(oldp+118,(vlSelf->tb_top__DOT__i),32);
}

void Vtb_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
