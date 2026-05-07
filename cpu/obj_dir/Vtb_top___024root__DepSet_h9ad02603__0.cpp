// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top__pch.h"
#include "Vtb_top___024root.h"

VL_ATTR_COLD void Vtb_top___024root___eval_initial__TOP(Vtb_top___024root* vlSelf);
VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__0(Vtb_top___024root* vlSelf);
VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__1(Vtb_top___024root* vlSelf);

void Vtb_top___024root___eval_initial(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_initial\n"); );
    // Body
    Vtb_top___024root___eval_initial__TOP(vlSelf);
    Vtb_top___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_top___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_top__DOT__clk__0 
        = vlSelf->tb_top__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_top__DOT__rst_n__0 
        = vlSelf->tb_top__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__0(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->tb_top__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb_top.v", 
                                           41);
        vlSelf->tb_top__DOT__clk = (1U & (~ (IData)(vlSelf->tb_top__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vtb_top___024root___eval_initial__TOP__Vtiming__1(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    vlSelf->tb_top__DOT__rst_n = 0U;
    co_await vlSelf->__VdlySched.delay(0x9c40ULL, nullptr, 
                                       "tb_top.v", 
                                       46);
    vlSelf->tb_top__DOT__rst_n = 1U;
}

void Vtb_top___024root___eval_act(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_top___024root___nba_sequent__TOP__0(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__tb_top__DOT__dut__DOT__pc_id;
    __Vdly__tb_top__DOT__dut__DOT__pc_id = 0;
    IData/*31:0*/ __Vdly__tb_top__DOT__dut__DOT__pc_plus4_id;
    __Vdly__tb_top__DOT__dut__DOT__pc_plus4_id = 0;
    CData/*4:0*/ __Vdlyvdim0__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0;
    __Vdlyvdim0__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0;
    __Vdlyvval__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0;
    __Vdlyvset__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v1;
    __Vdlyvset__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v1 = 0;
    // Body
    __Vdly__tb_top__DOT__dut__DOT__pc_plus4_id = vlSelf->tb_top__DOT__dut__DOT__pc_plus4_id;
    __Vdly__tb_top__DOT__dut__DOT__pc_id = vlSelf->tb_top__DOT__dut__DOT__pc_id;
    vlSelf->__Vdly__tb_top__DOT__dut__DOT__instr_id 
        = vlSelf->tb_top__DOT__dut__DOT__instr_id;
    __Vdlyvset__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0 = 0U;
    __Vdlyvset__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v1 = 0U;
    if ((1U & (~ (IData)(vlSelf->tb_top__DOT__rst_n)))) {
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i = 0x20U;
    }
    if (vlSelf->tb_top__DOT__rst_n) {
        if (vlSelf->tb_top__DOT__dut__DOT__if_id_stall) {
            __Vdly__tb_top__DOT__dut__DOT__pc_plus4_id 
                = vlSelf->tb_top__DOT__dut__DOT__pc_plus4_id;
            __Vdly__tb_top__DOT__dut__DOT__pc_id = vlSelf->tb_top__DOT__dut__DOT__pc_id;
            vlSelf->__Vdly__tb_top__DOT__dut__DOT__instr_id 
                = vlSelf->tb_top__DOT__dut__DOT__instr_id;
        } else if (vlSelf->tb_top__DOT__dut__DOT__if_id_flush) {
            __Vdly__tb_top__DOT__dut__DOT__pc_plus4_id = 0U;
            __Vdly__tb_top__DOT__dut__DOT__pc_id = 0U;
            vlSelf->__Vdly__tb_top__DOT__dut__DOT__instr_id = 0U;
        } else {
            __Vdly__tb_top__DOT__dut__DOT__pc_plus4_id 
                = ((IData)(4U) + vlSelf->tb_top__DOT__dut__DOT__pc_if);
            __Vdly__tb_top__DOT__dut__DOT__pc_id = vlSelf->tb_top__DOT__dut__DOT__pc_if;
            vlSelf->__Vdly__tb_top__DOT__dut__DOT__instr_id 
                = vlSelf->tb_top__DOT__imem[(0x3ffU 
                                             & (vlSelf->tb_top__DOT__dut__DOT__pc_if 
                                                >> 2U))];
        }
        if (((IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_wb) 
             & (0U != (IData)(vlSelf->tb_top__DOT__dut__DOT__rd_wb)))) {
            __Vdlyvval__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0 
                = vlSelf->tb_top__DOT__dut__DOT__wb_data;
            __Vdlyvset__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0 = 1U;
            __Vdlyvdim0__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0 
                = vlSelf->tb_top__DOT__dut__DOT__rd_wb;
        }
        vlSelf->tb_top__DOT__dut__DOT__mem_data_wb 
            = vlSelf->tb_top__DOT__dmem_rdata;
        vlSelf->tb_top__DOT__dut__DOT__pc_plus4_wb 
            = vlSelf->tb_top__DOT__dut__DOT__pc_plus4_mem;
        vlSelf->tb_top__DOT__dut__DOT__alu_result_wb 
            = vlSelf->tb_top__DOT__dut__DOT__alu_result_mem;
        if ((1U & (~ (IData)(vlSelf->tb_top__DOT__dut__DOT__pc_stall)))) {
            vlSelf->tb_top__DOT__dut__DOT__pc_if = vlSelf->tb_top__DOT__dut__DOT__pc_next_if;
        }
        vlSelf->tb_top__DOT__dut__DOT__pc_plus4_mem 
            = vlSelf->tb_top__DOT__dut__DOT__pc_plus4_ex;
    } else {
        __Vdly__tb_top__DOT__dut__DOT__pc_plus4_id = 0U;
        __Vdly__tb_top__DOT__dut__DOT__pc_id = 0U;
        vlSelf->__Vdly__tb_top__DOT__dut__DOT__instr_id = 0U;
        __Vdlyvset__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v1 = 1U;
        vlSelf->tb_top__DOT__dut__DOT__mem_data_wb = 0U;
        vlSelf->tb_top__DOT__dut__DOT__pc_plus4_wb = 0U;
        vlSelf->tb_top__DOT__dut__DOT__alu_result_wb = 0U;
        vlSelf->tb_top__DOT__dut__DOT__pc_if = 0U;
        vlSelf->tb_top__DOT__dut__DOT__pc_plus4_mem = 0U;
    }
    if ((1U & ((~ (IData)(vlSelf->tb_top__DOT__rst_n)) 
               | (IData)(vlSelf->tb_top__DOT__dut__DOT__id_ex_flush)))) {
        vlSelf->tb_top__DOT__dut__DOT__pc_ex = 0U;
        vlSelf->tb_top__DOT__dut__DOT__alu_op_ex = 0U;
        vlSelf->tb_top__DOT__dut__DOT__imm_ex = 0U;
        vlSelf->tb_top__DOT__dut__DOT__instr_ex = 0U;
        vlSelf->tb_top__DOT__dut__DOT__rs1_ex = 0U;
        vlSelf->tb_top__DOT__dut__DOT__rs2_ex = 0U;
        vlSelf->tb_top__DOT__dut__DOT__rs1_data_ex = 0U;
        vlSelf->tb_top__DOT__dut__DOT__rs2_data_ex = 0U;
    } else {
        vlSelf->tb_top__DOT__dut__DOT__pc_ex = vlSelf->tb_top__DOT__dut__DOT__pc_id;
        vlSelf->tb_top__DOT__dut__DOT__alu_op_ex = vlSelf->tb_top__DOT__dut__DOT__alu_op_id;
        vlSelf->tb_top__DOT__dut__DOT__imm_ex = vlSelf->tb_top__DOT__dut__DOT__imm_id;
        vlSelf->tb_top__DOT__dut__DOT__instr_ex = vlSelf->tb_top__DOT__dut__DOT__instr_id;
        vlSelf->tb_top__DOT__dut__DOT__rs1_ex = (0x1fU 
                                                 & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                    >> 0xfU));
        vlSelf->tb_top__DOT__dut__DOT__rs2_ex = (0x1fU 
                                                 & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                    >> 0x14U));
        vlSelf->tb_top__DOT__dut__DOT__rs1_data_ex 
            = ((0U == (0x1fU & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                >> 0xfU))) ? 0U : (
                                                   ((IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_wb) 
                                                    & ((0x1fU 
                                                        & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                           >> 0xfU)) 
                                                       == (IData)(vlSelf->tb_top__DOT__dut__DOT__rd_wb)))
                                                    ? vlSelf->tb_top__DOT__dut__DOT__wb_data
                                                    : 
                                                   vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs
                                                   [
                                                   (0x1fU 
                                                    & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                       >> 0xfU))]));
        vlSelf->tb_top__DOT__dut__DOT__rs2_data_ex 
            = ((0U == (0x1fU & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                >> 0x14U))) ? 0U : 
               (((IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_wb) 
                 & ((0x1fU & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                              >> 0x14U)) == (IData)(vlSelf->tb_top__DOT__dut__DOT__rd_wb)))
                 ? vlSelf->tb_top__DOT__dut__DOT__wb_data
                 : vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs
                [(0x1fU & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                           >> 0x14U))]));
    }
    if (vlSelf->tb_top__DOT__rst_n) {
        vlSelf->tb_top__DOT__dut__DOT__rd_wb = vlSelf->tb_top__DOT__dut__DOT__rd_mem;
        vlSelf->tb_top__DOT__dut__DOT__rd_mem = vlSelf->tb_top__DOT__dut__DOT__rd_ex;
    } else {
        vlSelf->tb_top__DOT__dut__DOT__rd_wb = 0U;
        vlSelf->tb_top__DOT__dut__DOT__rd_mem = 0U;
    }
    if ((1U & ((~ (IData)(vlSelf->tb_top__DOT__rst_n)) 
               | (IData)(vlSelf->tb_top__DOT__dut__DOT__id_ex_flush)))) {
        vlSelf->tb_top__DOT__dut__DOT__pc_plus4_ex = 0U;
        vlSelf->tb_top__DOT__dut__DOT__rd_ex = 0U;
    } else {
        vlSelf->tb_top__DOT__dut__DOT__pc_plus4_ex 
            = vlSelf->tb_top__DOT__dut__DOT__pc_plus4_id;
        vlSelf->tb_top__DOT__dut__DOT__rd_ex = (0x1fU 
                                                & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                   >> 7U));
    }
    vlSelf->tb_top__DOT__dut__DOT__alu_src_ex = ((1U 
                                                  & (~ 
                                                     ((~ (IData)(vlSelf->tb_top__DOT__rst_n)) 
                                                      | (IData)(vlSelf->tb_top__DOT__dut__DOT__id_ex_flush)))) 
                                                 && (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_src_id));
    vlSelf->tb_top__DOT__dut__DOT__branch_ex = ((1U 
                                                 & (~ 
                                                    ((~ (IData)(vlSelf->tb_top__DOT__rst_n)) 
                                                     | (IData)(vlSelf->tb_top__DOT__dut__DOT__id_ex_flush)))) 
                                                && (IData)(vlSelf->tb_top__DOT__dut__DOT__branch_id));
    vlSelf->tb_top__DOT__dut__DOT__mem_read_mem = ((IData)(vlSelf->tb_top__DOT__rst_n) 
                                                   && (IData)(vlSelf->tb_top__DOT__dut__DOT__mem_read_ex));
    vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_wb = 
        ((IData)(vlSelf->tb_top__DOT__rst_n) && (IData)(vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_mem));
    vlSelf->tb_top__DOT__dut__DOT__jump_wb = ((IData)(vlSelf->tb_top__DOT__rst_n) 
                                              && (IData)(vlSelf->tb_top__DOT__dut__DOT__jump_mem));
    vlSelf->tb_top__DOT__dut__DOT__pc_id = __Vdly__tb_top__DOT__dut__DOT__pc_id;
    if (__Vdlyvset__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0) {
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[__Vdlyvdim0__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0] 
            = __Vdlyvval__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v0;
    }
    if (__Vdlyvset__tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs__v1) {
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[1U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[2U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[3U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[4U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[5U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[6U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[7U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[8U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[9U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0xaU] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0xbU] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0xcU] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0xdU] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0xeU] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0xfU] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x10U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x11U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x12U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x13U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x14U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x15U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x16U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x17U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x18U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x19U] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x1aU] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x1bU] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x1cU] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x1dU] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x1eU] = 0U;
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[0x1fU] = 0U;
    }
    vlSelf->tb_top__DOT__dut__DOT__branch_target = 
        (vlSelf->tb_top__DOT__dut__DOT__imm_ex + vlSelf->tb_top__DOT__dut__DOT__pc_ex);
    vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex = ((2U 
                                                   & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_op_ex))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_op_ex))
                                                    ? 
                                                   ((0x37U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_ex))
                                                     ? 0xaU
                                                     : 0U)
                                                    : 
                                                   ((0x4000U 
                                                     & vlSelf->tb_top__DOT__dut__DOT__instr_ex)
                                                     ? 
                                                    ((0x2000U 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_ex)
                                                      ? 
                                                     ((0x1000U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_ex)
                                                       ? 2U
                                                       : 3U)
                                                      : 
                                                     ((0x1000U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_ex)
                                                       ? 
                                                      ((0x40000000U 
                                                        & vlSelf->tb_top__DOT__dut__DOT__instr_ex)
                                                        ? 7U
                                                        : 6U)
                                                       : 4U))
                                                     : 
                                                    ((0x2000U 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_ex)
                                                      ? 
                                                     ((0x1000U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_ex)
                                                       ? 9U
                                                       : 8U)
                                                      : 
                                                     ((0x1000U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_ex)
                                                       ? 5U
                                                       : 0U))))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_op_ex))
                                                    ? 
                                                   ((0x4000U 
                                                     & vlSelf->tb_top__DOT__dut__DOT__instr_ex)
                                                     ? 
                                                    ((0x2000U 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_ex)
                                                      ? 9U
                                                      : 8U)
                                                     : 1U)
                                                    : 0U));
    vlSelf->tb_top__DOT__dut__DOT__mem_read_ex = ((1U 
                                                   & (~ 
                                                      ((~ (IData)(vlSelf->tb_top__DOT__rst_n)) 
                                                       | (IData)(vlSelf->tb_top__DOT__dut__DOT__id_ex_flush)))) 
                                                  && (IData)(vlSelf->tb_top__DOT__dut__DOT__mem_read_id));
    vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_mem = 
        ((IData)(vlSelf->tb_top__DOT__rst_n) && (IData)(vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_ex));
    vlSelf->tb_top__DOT__dut__DOT__jump_mem = ((IData)(vlSelf->tb_top__DOT__rst_n) 
                                               && (IData)(vlSelf->tb_top__DOT__dut__DOT__jump_ex));
    vlSelf->tb_top__DOT__dut__DOT__wb_data = ((IData)(vlSelf->tb_top__DOT__dut__DOT__jump_wb)
                                               ? vlSelf->tb_top__DOT__dut__DOT__pc_plus4_wb
                                               : ((IData)(vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_wb)
                                                   ? vlSelf->tb_top__DOT__dut__DOT__mem_data_wb
                                                   : vlSelf->tb_top__DOT__dut__DOT__alu_result_wb));
    vlSelf->tb_top__DOT__dut__DOT__reg_write_wb = ((IData)(vlSelf->tb_top__DOT__rst_n) 
                                                   && (IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_mem));
    vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_ex = 
        ((1U & (~ ((~ (IData)(vlSelf->tb_top__DOT__rst_n)) 
                   | (IData)(vlSelf->tb_top__DOT__dut__DOT__id_ex_flush)))) 
         && (IData)(vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_id));
    vlSelf->tb_top__DOT__dut__DOT__jump_ex = ((1U & 
                                               (~ (
                                                   (~ (IData)(vlSelf->tb_top__DOT__rst_n)) 
                                                   | (IData)(vlSelf->tb_top__DOT__dut__DOT__id_ex_flush)))) 
                                              && (IData)(vlSelf->tb_top__DOT__dut__DOT__jump_id));
    vlSelf->tb_top__DOT__dut__DOT__reg_write_mem = 
        ((IData)(vlSelf->tb_top__DOT__rst_n) && (IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_ex));
    vlSelf->tb_top__DOT__dut__DOT__pc_plus4_id = __Vdly__tb_top__DOT__dut__DOT__pc_plus4_id;
    vlSelf->tb_top__DOT__dut__DOT__reg_write_ex = (
                                                   (1U 
                                                    & (~ 
                                                       ((~ (IData)(vlSelf->tb_top__DOT__rst_n)) 
                                                        | (IData)(vlSelf->tb_top__DOT__dut__DOT__id_ex_flush)))) 
                                                   && (IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_id));
    vlSelf->tb_top__DOT__dut__DOT__forward_a = 0U;
    if ((((IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_mem) 
          & (0U != (IData)(vlSelf->tb_top__DOT__dut__DOT__rd_mem))) 
         & ((IData)(vlSelf->tb_top__DOT__dut__DOT__rd_mem) 
            == (IData)(vlSelf->tb_top__DOT__dut__DOT__rs1_ex)))) {
        vlSelf->tb_top__DOT__dut__DOT__forward_a = 2U;
    } else if ((((IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_wb) 
                 & (0U != (IData)(vlSelf->tb_top__DOT__dut__DOT__rd_wb))) 
                & ((IData)(vlSelf->tb_top__DOT__dut__DOT__rd_wb) 
                   == (IData)(vlSelf->tb_top__DOT__dut__DOT__rs1_ex)))) {
        vlSelf->tb_top__DOT__dut__DOT__forward_a = 1U;
    }
    vlSelf->tb_top__DOT__dut__DOT__forward_b = 0U;
    if ((((IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_mem) 
          & (0U != (IData)(vlSelf->tb_top__DOT__dut__DOT__rd_mem))) 
         & ((IData)(vlSelf->tb_top__DOT__dut__DOT__rd_mem) 
            == (IData)(vlSelf->tb_top__DOT__dut__DOT__rs2_ex)))) {
        vlSelf->tb_top__DOT__dut__DOT__forward_b = 2U;
    } else if ((((IData)(vlSelf->tb_top__DOT__dut__DOT__reg_write_wb) 
                 & (0U != (IData)(vlSelf->tb_top__DOT__dut__DOT__rd_wb))) 
                & ((IData)(vlSelf->tb_top__DOT__dut__DOT__rd_wb) 
                   == (IData)(vlSelf->tb_top__DOT__dut__DOT__rs2_ex)))) {
        vlSelf->tb_top__DOT__dut__DOT__forward_b = 1U;
    }
}

VL_INLINE_OPT void Vtb_top___024root___nba_sequent__TOP__1(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSelf->tb_top__DOT__dut__DOT__mem_write_mem) {
        if ((0U == (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_mem))) {
            vlSelf->tb_top__DOT__dmem[(0xfffU & vlSelf->tb_top__DOT__dut__DOT__alu_result_mem)] 
                = (0xffU & vlSelf->tb_top__DOT__dut__DOT__rs2_data_mem);
        } else if ((1U == (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_mem))) {
            vlSelf->tb_top__DOT__dmem[(0xfffU & ((IData)(1U) 
                                                 + vlSelf->tb_top__DOT__dut__DOT__alu_result_mem))] 
                = (0xffU & (vlSelf->tb_top__DOT__dut__DOT__rs2_data_mem 
                            >> 8U));
            vlSelf->tb_top__DOT__dmem[(0xfffU & vlSelf->tb_top__DOT__dut__DOT__alu_result_mem)] 
                = (0xffU & vlSelf->tb_top__DOT__dut__DOT__rs2_data_mem);
        } else if ((2U == (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_mem))) {
            vlSelf->tb_top__DOT__dmem[(0xfffU & ((IData)(3U) 
                                                 + vlSelf->tb_top__DOT__dut__DOT__alu_result_mem))] 
                = (vlSelf->tb_top__DOT__dut__DOT__rs2_data_mem 
                   >> 0x18U);
            vlSelf->tb_top__DOT__dmem[(0xfffU & ((IData)(2U) 
                                                 + vlSelf->tb_top__DOT__dut__DOT__alu_result_mem))] 
                = (0xffU & (vlSelf->tb_top__DOT__dut__DOT__rs2_data_mem 
                            >> 0x10U));
            vlSelf->tb_top__DOT__dmem[(0xfffU & ((IData)(1U) 
                                                 + vlSelf->tb_top__DOT__dut__DOT__alu_result_mem))] 
                = (0xffU & (vlSelf->tb_top__DOT__dut__DOT__rs2_data_mem 
                            >> 8U));
            vlSelf->tb_top__DOT__dmem[(0xfffU & vlSelf->tb_top__DOT__dut__DOT__alu_result_mem)] 
                = (0xffU & vlSelf->tb_top__DOT__dut__DOT__rs2_data_mem);
        }
    }
}

extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_h03c3adda_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_h7565b13f_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtb_top__ConstPool__TABLE_hff76da65_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_h7ca8bf9e_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_ha96ed2bf_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_he4685dc5_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_hbd434190_0;

VL_INLINE_OPT void Vtb_top___024root___nba_sequent__TOP__2(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    if (vlSelf->tb_top__DOT__rst_n) {
        vlSelf->tb_top__DOT__dut__DOT__rs2_data_mem 
            = vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded;
        vlSelf->tb_top__DOT__dut__DOT__func3_mem = vlSelf->tb_top__DOT__dut__DOT__func3_ex;
        vlSelf->tb_top__DOT__dut__DOT__alu_result_mem 
            = vlSelf->tb_top__DOT__dut__DOT__alu_result_ex;
    } else {
        vlSelf->tb_top__DOT__dut__DOT__rs2_data_mem = 0U;
        vlSelf->tb_top__DOT__dut__DOT__func3_mem = 0U;
        vlSelf->tb_top__DOT__dut__DOT__alu_result_mem = 0U;
    }
    vlSelf->tb_top__DOT__dut__DOT__mem_write_mem = 
        ((IData)(vlSelf->tb_top__DOT__rst_n) && (IData)(vlSelf->tb_top__DOT__dut__DOT__mem_write_ex));
    vlSelf->tb_top__DOT__dut__DOT__mem_write_ex = (
                                                   (1U 
                                                    & (~ 
                                                       ((~ (IData)(vlSelf->tb_top__DOT__rst_n)) 
                                                        | (IData)(vlSelf->tb_top__DOT__dut__DOT__id_ex_flush)))) 
                                                   && (IData)(vlSelf->tb_top__DOT__dut__DOT__mem_write_id));
    vlSelf->tb_top__DOT__dut__DOT__func3_ex = ((1U 
                                                & ((~ (IData)(vlSelf->tb_top__DOT__rst_n)) 
                                                   | (IData)(vlSelf->tb_top__DOT__dut__DOT__id_ex_flush)))
                                                ? 0U
                                                : (7U 
                                                   & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                      >> 0xcU)));
    vlSelf->tb_top__DOT__dut__DOT__alu_a_ex = ((1U 
                                                == (IData)(vlSelf->tb_top__DOT__dut__DOT__forward_a))
                                                ? vlSelf->tb_top__DOT__dut__DOT__wb_data
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelf->tb_top__DOT__dut__DOT__forward_a))
                                                    ? vlSelf->tb_top__DOT__dut__DOT__alu_result_mem
                                                    : vlSelf->tb_top__DOT__dut__DOT__rs1_data_ex));
    vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded = 
        ((1U == (IData)(vlSelf->tb_top__DOT__dut__DOT__forward_b))
          ? vlSelf->tb_top__DOT__dut__DOT__wb_data : 
         ((2U == (IData)(vlSelf->tb_top__DOT__dut__DOT__forward_b))
           ? vlSelf->tb_top__DOT__dut__DOT__alu_result_mem
           : vlSelf->tb_top__DOT__dut__DOT__rs2_data_ex));
    vlSelf->tb_top__DOT__dut__DOT__instr_id = vlSelf->__Vdly__tb_top__DOT__dut__DOT__instr_id;
    vlSelf->tb_top__DOT__dut__DOT__alu_b_ex = ((IData)(vlSelf->tb_top__DOT__dut__DOT__alu_src_ex)
                                                ? vlSelf->tb_top__DOT__dut__DOT__imm_ex
                                                : vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded);
    vlSelf->tb_top__DOT__dut__DOT__branch_taken = ((IData)(vlSelf->tb_top__DOT__dut__DOT__branch_ex) 
                                                   & ((4U 
                                                       & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                                         ? 
                                                        (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                                         >= vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)
                                                         : 
                                                        (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                                         < vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                                         ? 
                                                        VL_GTES_III(32, vlSelf->tb_top__DOT__dut__DOT__alu_a_ex, vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)
                                                         : 
                                                        VL_LTS_III(32, vlSelf->tb_top__DOT__dut__DOT__alu_a_ex, vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)))
                                                       : 
                                                      ((1U 
                                                        & (~ 
                                                           ((IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex) 
                                                            >> 1U))) 
                                                       && ((1U 
                                                            & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_ex))
                                                            ? 
                                                           (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                                            != vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)
                                                            : 
                                                           (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                                                            == vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded)))));
    vlSelf->tb_top__DOT__dut__DOT__imm_id = ((0x40U 
                                              & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                              ? ((0x20U 
                                                  & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                  ? 
                                                 ((0x10U 
                                                   & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                   ? 0U
                                                   : 
                                                  ((8U 
                                                    & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                    ? 
                                                   ((4U 
                                                     & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                     ? 
                                                    ((2U 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                    >> 0x1fU))) 
                                                        << 0x15U) 
                                                       | ((0x100000U 
                                                           & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                              >> 0xbU)) 
                                                          | ((0xff000U 
                                                              & vlSelf->tb_top__DOT__dut__DOT__instr_id) 
                                                             | ((0x800U 
                                                                 & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                    >> 9U)) 
                                                                | (0x7feU 
                                                                   & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                      >> 0x14U))))))
                                                       : 0U)
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                     ? 
                                                    ((2U 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                    >> 0x1fU))) 
                                                        << 0xcU) 
                                                       | (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                          >> 0x14U))
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((2U 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                    >> 0x1fU))) 
                                                        << 0xdU) 
                                                       | ((0x1000U 
                                                           & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                              >> 0x13U)) 
                                                          | ((0x800U 
                                                              & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                 << 4U)) 
                                                             | ((0x7e0U 
                                                                 & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                    >> 0x14U)) 
                                                                | (0x1eU 
                                                                   & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                      >> 7U))))))
                                                       : 0U)
                                                      : 0U))))
                                                  : 0U)
                                              : ((0x20U 
                                                  & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                  ? 
                                                 ((0x10U 
                                                   & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                   ? 
                                                  ((8U 
                                                    & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                     ? 
                                                    ((2U 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                       ? 
                                                      (0xfffff000U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                       : 0U)
                                                      : 0U)
                                                     : 0U))
                                                   : 
                                                  ((8U 
                                                    & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                    >> 0x1fU))) 
                                                        << 0xcU) 
                                                       | ((0xfe0U 
                                                           & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                              >> 0x14U)) 
                                                          | (0x1fU 
                                                             & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                >> 7U))))
                                                       : 0U)
                                                      : 0U))))
                                                  : 
                                                 ((0x10U 
                                                   & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                   ? 
                                                  ((8U 
                                                    & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                     ? 
                                                    ((2U 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                       ? 
                                                      (0xfffff000U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((2U 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                    >> 0x1fU))) 
                                                        << 0xcU) 
                                                       | (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                          >> 0x14U))
                                                       : 0U)
                                                      : 0U)))
                                                   : 
                                                  ((8U 
                                                    & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_top__DOT__dut__DOT__instr_id)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                                    >> 0x1fU))) 
                                                        << 0xcU) 
                                                       | (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                          >> 0x14U))
                                                       : 0U)
                                                      : 0U))))));
    vlSelf->tb_top__DOT__dut__DOT__hazard_inst__DOT__load_use_hazard 
        = ((IData)(vlSelf->tb_top__DOT__dut__DOT__mem_read_ex) 
           & ((((IData)(vlSelf->tb_top__DOT__dut__DOT__rd_ex) 
                == (0x1fU & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                             >> 0xfU))) | ((IData)(vlSelf->tb_top__DOT__dut__DOT__rd_ex) 
                                           == (0x1fU 
                                               & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                  >> 0x14U)))) 
              & (0U != (IData)(vlSelf->tb_top__DOT__dut__DOT__rd_ex))));
    __Vtableidx1 = (0x7fU & vlSelf->tb_top__DOT__dut__DOT__instr_id);
    vlSelf->tb_top__DOT__dut__DOT__reg_write_id = Vtb_top__ConstPool__TABLE_h03c3adda_0
        [__Vtableidx1];
    vlSelf->tb_top__DOT__dut__DOT__alu_src_id = Vtb_top__ConstPool__TABLE_h7565b13f_0
        [__Vtableidx1];
    vlSelf->tb_top__DOT__dut__DOT__alu_op_id = Vtb_top__ConstPool__TABLE_hff76da65_0
        [__Vtableidx1];
    vlSelf->tb_top__DOT__dut__DOT__mem_read_id = Vtb_top__ConstPool__TABLE_h7ca8bf9e_0
        [__Vtableidx1];
    vlSelf->tb_top__DOT__dut__DOT__mem_write_id = Vtb_top__ConstPool__TABLE_ha96ed2bf_0
        [__Vtableidx1];
    vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_id = 
        Vtb_top__ConstPool__TABLE_h7ca8bf9e_0[__Vtableidx1];
    vlSelf->tb_top__DOT__dut__DOT__branch_id = Vtb_top__ConstPool__TABLE_he4685dc5_0
        [__Vtableidx1];
    vlSelf->tb_top__DOT__dut__DOT__jump_id = Vtb_top__ConstPool__TABLE_hbd434190_0
        [__Vtableidx1];
    vlSelf->tb_top__DOT__dut__DOT__alu_result_ex = 
        ((8U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
          ? ((4U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
              ? 0U : ((2U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
                       ? ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
                           ? 0U : vlSelf->tb_top__DOT__dut__DOT__alu_b_ex)
                       : ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
                           ? ((vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                               < vlSelf->tb_top__DOT__dut__DOT__alu_b_ex)
                               ? 1U : 0U) : (VL_LTS_III(32, vlSelf->tb_top__DOT__dut__DOT__alu_a_ex, vlSelf->tb_top__DOT__dut__DOT__alu_b_ex)
                                              ? 1U : 0U))))
          : ((4U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
              ? ((2U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
                  ? ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
                      ? VL_SHIFTRS_III(32,32,5, vlSelf->tb_top__DOT__dut__DOT__alu_a_ex, 
                                       (0x1fU & vlSelf->tb_top__DOT__dut__DOT__alu_b_ex))
                      : (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                         >> (0x1fU & vlSelf->tb_top__DOT__dut__DOT__alu_b_ex)))
                  : ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
                      ? (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                         << (0x1fU & vlSelf->tb_top__DOT__dut__DOT__alu_b_ex))
                      : (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                         ^ vlSelf->tb_top__DOT__dut__DOT__alu_b_ex)))
              : ((2U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
                  ? ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
                      ? (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                         | vlSelf->tb_top__DOT__dut__DOT__alu_b_ex)
                      : (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                         & vlSelf->tb_top__DOT__dut__DOT__alu_b_ex))
                  : ((1U & (IData)(vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex))
                      ? (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                         - vlSelf->tb_top__DOT__dut__DOT__alu_b_ex)
                      : (vlSelf->tb_top__DOT__dut__DOT__alu_a_ex 
                         + vlSelf->tb_top__DOT__dut__DOT__alu_b_ex)))));
    vlSelf->tb_top__DOT__dut__DOT__if_id_flush = 0U;
    vlSelf->tb_top__DOT__dut__DOT__pc_stall = 0U;
    vlSelf->tb_top__DOT__dut__DOT__if_id_stall = 0U;
    vlSelf->tb_top__DOT__dut__DOT__id_ex_flush = 0U;
    if (vlSelf->tb_top__DOT__dut__DOT__hazard_inst__DOT__load_use_hazard) {
        vlSelf->tb_top__DOT__dut__DOT__pc_stall = 1U;
        vlSelf->tb_top__DOT__dut__DOT__if_id_stall = 1U;
        vlSelf->tb_top__DOT__dut__DOT__id_ex_flush = 1U;
    }
    if (((IData)(vlSelf->tb_top__DOT__dut__DOT__branch_taken) 
         | (IData)(vlSelf->tb_top__DOT__dut__DOT__jump_ex))) {
        vlSelf->tb_top__DOT__dut__DOT__if_id_flush = 1U;
        vlSelf->tb_top__DOT__dut__DOT__id_ex_flush = 1U;
    }
    vlSelf->tb_top__DOT__dut__DOT__pc_next_if = ((IData)(vlSelf->tb_top__DOT__dut__DOT__jump_ex)
                                                  ? 
                                                 ((0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->tb_top__DOT__dut__DOT__instr_ex))
                                                   ? vlSelf->tb_top__DOT__dut__DOT__branch_target
                                                   : 
                                                  (0xfffffffeU 
                                                   & vlSelf->tb_top__DOT__dut__DOT__alu_result_ex))
                                                  : 
                                                 ((IData)(vlSelf->tb_top__DOT__dut__DOT__branch_taken)
                                                   ? vlSelf->tb_top__DOT__dut__DOT__branch_target
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlSelf->tb_top__DOT__dut__DOT__pc_if)));
}

VL_INLINE_OPT void Vtb_top___024root___nba_comb__TOP__0(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->tb_top__DOT__dmem_rdata = ((IData)(vlSelf->tb_top__DOT__dut__DOT__mem_read_mem)
                                        ? ((4U & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_mem))
                                            ? ((2U 
                                                & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_mem))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_mem))
                                                    ? 
                                                   ((vlSelf->tb_top__DOT__dmem
                                                     [
                                                     (0xfffU 
                                                      & ((IData)(1U) 
                                                         + vlSelf->tb_top__DOT__dut__DOT__alu_result_mem))] 
                                                     << 8U) 
                                                    | vlSelf->tb_top__DOT__dmem
                                                    [
                                                    (0xfffU 
                                                     & vlSelf->tb_top__DOT__dut__DOT__alu_result_mem)])
                                                    : 
                                                   vlSelf->tb_top__DOT__dmem
                                                   [
                                                   (0xfffU 
                                                    & vlSelf->tb_top__DOT__dut__DOT__alu_result_mem)]))
                                            : ((2U 
                                                & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_mem))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_mem))
                                                    ? 0U
                                                    : 
                                                   ((vlSelf->tb_top__DOT__dmem
                                                     [
                                                     (0xfffU 
                                                      & ((IData)(3U) 
                                                         + vlSelf->tb_top__DOT__dut__DOT__alu_result_mem))] 
                                                     << 0x18U) 
                                                    | ((vlSelf->tb_top__DOT__dmem
                                                        [
                                                        (0xfffU 
                                                         & ((IData)(2U) 
                                                            + vlSelf->tb_top__DOT__dut__DOT__alu_result_mem))] 
                                                        << 0x10U) 
                                                       | ((vlSelf->tb_top__DOT__dmem
                                                           [
                                                           (0xfffU 
                                                            & ((IData)(1U) 
                                                               + vlSelf->tb_top__DOT__dut__DOT__alu_result_mem))] 
                                                           << 8U) 
                                                          | vlSelf->tb_top__DOT__dmem
                                                          [
                                                          (0xfffU 
                                                           & vlSelf->tb_top__DOT__dut__DOT__alu_result_mem)]))))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->tb_top__DOT__dut__DOT__func3_mem))
                                                    ? 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->tb_top__DOT__dmem
                                                                    [
                                                                    (0xfffU 
                                                                     & ((IData)(1U) 
                                                                        + vlSelf->tb_top__DOT__dut__DOT__alu_result_mem))] 
                                                                    >> 7U)))) 
                                                     << 0x10U) 
                                                    | ((vlSelf->tb_top__DOT__dmem
                                                        [
                                                        (0xfffU 
                                                         & ((IData)(1U) 
                                                            + vlSelf->tb_top__DOT__dut__DOT__alu_result_mem))] 
                                                        << 8U) 
                                                       | vlSelf->tb_top__DOT__dmem
                                                       [
                                                       (0xfffU 
                                                        & vlSelf->tb_top__DOT__dut__DOT__alu_result_mem)]))
                                                    : 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->tb_top__DOT__dmem
                                                                    [
                                                                    (0xfffU 
                                                                     & vlSelf->tb_top__DOT__dut__DOT__alu_result_mem)] 
                                                                    >> 7U)))) 
                                                     << 8U) 
                                                    | vlSelf->tb_top__DOT__dmem
                                                    [
                                                    (0xfffU 
                                                     & vlSelf->tb_top__DOT__dut__DOT__alu_result_mem)]))))
                                        : 0U);
}

void Vtb_top___024root___eval_nba(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_top___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_top___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vtb_top___024root___timing_resume(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___timing_resume\n"); );
    // Body
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_top___024root___eval_triggers__act(Vtb_top___024root* vlSelf);

bool Vtb_top___024root___eval_phase__act(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_top___024root___timing_resume(vlSelf);
        Vtb_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_top___024root___eval_phase__nba(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__nba(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__act(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_top___024root___eval(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_top.v", 18, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_top.v", 18, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_top___024root___eval_debug_assertions(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
