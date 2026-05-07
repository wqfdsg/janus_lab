// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top__pch.h"
#include "Vtb_top___024root.h"

VL_ATTR_COLD void Vtb_top___024root___eval_static(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_top___024root___eval_final(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__stl(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_top___024root___eval_phase__stl(Vtb_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_top___024root___eval_settle(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb_top.v", 18, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__stl(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_h03c3adda_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_h7565b13f_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtb_top__ConstPool__TABLE_hff76da65_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_h7ca8bf9e_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_ha96ed2bf_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_he4685dc5_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_top__ConstPool__TABLE_hbd434190_0;

VL_ATTR_COLD void Vtb_top___024root___stl_sequent__TOP__0(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
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
    vlSelf->tb_top__DOT__dut__DOT__branch_target = 
        (vlSelf->tb_top__DOT__dut__DOT__imm_ex + vlSelf->tb_top__DOT__dut__DOT__pc_ex);
    vlSelf->tb_top__DOT__dut__DOT__hazard_inst__DOT__load_use_hazard 
        = ((IData)(vlSelf->tb_top__DOT__dut__DOT__mem_read_ex) 
           & ((((IData)(vlSelf->tb_top__DOT__dut__DOT__rd_ex) 
                == (0x1fU & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                             >> 0xfU))) | ((IData)(vlSelf->tb_top__DOT__dut__DOT__rd_ex) 
                                           == (0x1fU 
                                               & (vlSelf->tb_top__DOT__dut__DOT__instr_id 
                                                  >> 0x14U)))) 
              & (0U != (IData)(vlSelf->tb_top__DOT__dut__DOT__rd_ex))));
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
    vlSelf->tb_top__DOT__dut__DOT__wb_data = ((IData)(vlSelf->tb_top__DOT__dut__DOT__jump_wb)
                                               ? vlSelf->tb_top__DOT__dut__DOT__pc_plus4_wb
                                               : ((IData)(vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_wb)
                                                   ? vlSelf->tb_top__DOT__dut__DOT__mem_data_wb
                                                   : vlSelf->tb_top__DOT__dut__DOT__alu_result_wb));
    vlSelf->tb_top__DOT__dut__DOT__pc_stall = 0U;
    vlSelf->tb_top__DOT__dut__DOT__if_id_stall = 0U;
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

VL_ATTR_COLD void Vtb_top___024root___eval_stl(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtb_top___024root___eval_triggers__stl(Vtb_top___024root* vlSelf);

VL_ATTR_COLD bool Vtb_top___024root___eval_phase__stl(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__act(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_top.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_top.clk or negedge tb_top.rst_n)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__nba(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_top.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_top.clk or negedge tb_top.rst_n)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_top___024root___ctor_var_reset(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_top__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dmem_rdata = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb_top__DOT__imem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_top__DOT__dmem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_top__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__forward_a = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__dut__DOT__forward_b = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__dut__DOT__alu_result_mem = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__rs2_data_mem = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__rd_mem = VL_RAND_RESET_I(5);
    vlSelf->tb_top__DOT__dut__DOT__reg_write_mem = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__mem_read_mem = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__mem_write_mem = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_mem = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__func3_mem = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__alu_result_wb = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__mem_data_wb = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__rd_wb = VL_RAND_RESET_I(5);
    vlSelf->tb_top__DOT__dut__DOT__reg_write_wb = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_wb = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__wb_data = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__pc_plus4_mem = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__pc_plus4_wb = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__jump_mem = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__jump_wb = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__rs2_forwarded = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__pc_if = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__pc_next_if = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__branch_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__branch_target = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__instr_ex = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__pc_id = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__pc_plus4_id = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__instr_id = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__reg_write_id = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__alu_src_id = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__mem_read_id = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__mem_write_id = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_id = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__branch_id = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__jump_id = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__alu_op_id = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__dut__DOT__imm_id = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__pc_ex = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__pc_plus4_ex = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__imm_ex = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__rs1_data_ex = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__rs2_data_ex = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__rd_ex = VL_RAND_RESET_I(5);
    vlSelf->tb_top__DOT__dut__DOT__rs1_ex = VL_RAND_RESET_I(5);
    vlSelf->tb_top__DOT__dut__DOT__rs2_ex = VL_RAND_RESET_I(5);
    vlSelf->tb_top__DOT__dut__DOT__func3_ex = VL_RAND_RESET_I(3);
    vlSelf->tb_top__DOT__dut__DOT__reg_write_ex = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__alu_src_ex = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__mem_read_ex = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__mem_write_ex = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__mem_to_reg_ex = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__branch_ex = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__jump_ex = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__alu_op_ex = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__dut__DOT__alu_ctrl_ex = VL_RAND_RESET_I(4);
    vlSelf->tb_top__DOT__dut__DOT__alu_a_ex = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__alu_b_ex = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__alu_result_ex = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__pc_stall = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__if_id_stall = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__if_id_flush = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__dut__DOT__id_ex_flush = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_top__DOT__dut__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__dut__DOT__hazard_inst__DOT__load_use_hazard = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_top__DOT__dut__DOT__instr_id = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__tb_top__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_top__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
