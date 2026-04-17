# Janus Lab — Tiny RISC-V CPU Specification

## Overview

This lab guides you through implementing a tiny 32-bit RISC-V CPU in Verilog. You will build the design in three phases, starting with a single-cycle datapath and progressing to a pipelined implementation with hazard handling.

---

## Target ISA: RV32I Base Integer

Implement the full RV32I base integer instruction set (47 instructions). Extensions (M, F, D, C) are out of scope unless specified as stretch goals.

### Instruction Types

| Type | Instructions |
|------|-------------|
| R    | `ADD`, `SUB`, `SLL`, `SLT`, `SLTU`, `XOR`, `SRL`, `SRA`, `OR`, `AND` |
| I    | `ADDI`, `SLTI`, `SLTIU`, `XORI`, `ORI`, `ANDI`, `SLLI`, `SRLI`, `SRAI` |
| I (load) | `LB`, `LH`, `LW`, `LBU`, `LHU` |
| S    | `SB`, `SH`, `SW` |
| B    | `BEQ`, `BNE`, `BLT`, `BGE`, `BLTU`, `BGEU` |
| U    | `LUI`, `AUIPC` |
| J    | `JAL`, `JALR` |

### Excluded (initially)
- `FENCE`, `ECALL`, `EBREAK` — may be added in Phase 3 as stretch goals

---

## Memory System

| Component       | Size  | Type          | Notes                                  |
|-----------------|-------|---------------|----------------------------------------|
| Instruction ROM | 4 KB  | Read-only     | Preloaded via `$readmemh` at sim start |
| Data RAM        | 4 KB  | Read/Write    | Byte-addressable, word-aligned access  |

- Harvard architecture: separate instruction and data memory buses
- All addresses are 32-bit; word addresses are 4-byte aligned
- Support byte (`LB`/`SB`), halfword (`LH`/`SH`), and word (`LW`/`SW`) accesses
- No caches in Phase 1 or Phase 2

---

## Phase 1 — Single-Cycle Datapath

### Goal
Implement a fully functional CPU where every instruction completes in exactly one clock cycle.

### Datapath Stages (combinational, no registers between them)

```
IF → ID → EX → MEM → WB
```

### Module Hierarchy

```
top
├── cpu
│   ├── pc_reg          # 32-bit program counter register
│   ├── imem            # instruction ROM
│   ├── reg_file        # 32×32 register file (x0 hardwired to 0)
│   ├── imm_gen         # immediate extension unit
│   ├── alu             # arithmetic/logic unit
│   ├── alu_ctrl        # ALU control decoder
│   ├── ctrl            # main control unit
│   ├── dmem            # data RAM
│   └── branch_unit     # branch condition evaluator
└── tb_top              # testbench (not synthesizable)
```

### Control Signals

| Signal      | Width | Description                                        |
|-------------|-------|----------------------------------------------------|
| `reg_write` | 1     | Enable write to register file                      |
| `alu_src`   | 1     | 0 = rs2, 1 = immediate                             |
| `alu_op`    | 2     | ALU operation class (R-type, I-type, branch, load/store) |
| `mem_read`  | 1     | Enable data memory read                            |
| `mem_write` | 1     | Enable data memory write                           |
| `mem_to_reg`| 1     | 0 = ALU result, 1 = memory data written to rd      |
| `branch`    | 1     | Instruction is a branch                            |
| `jump`      | 1     | Instruction is JAL or JALR                         |

### ALU Operations

The ALU must support: ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU, pass-through (for LUI).

### Deliverables
- All modules listed above implemented and passing individual unit tests
- Single-cycle CPU passing the Phase 1 test suite (see Verification section)

---

## Phase 2 — 5-Stage Pipeline

### Goal
Add pipeline registers between all five stages and implement the required hazard handling logic.

### Pipeline Registers

| Register   | Sits Between | Key Fields Carried Forward                        |
|------------|--------------|---------------------------------------------------|
| `IF_ID`    | IF / ID      | `pc`, `instr`                                     |
| `ID_EX`    | ID / EX      | `pc`, `rs1_data`, `rs2_data`, `imm`, `rd`, control signals |
| `EX_MEM`   | EX / MEM     | `alu_result`, `rs2_data`, `rd`, control signals   |
| `MEM_WB`   | MEM / WB     | `alu_result`, `mem_data`, `rd`, control signals   |

### Hazard Handling

#### Data Hazards — Forwarding Unit
Forward results to the EX stage input when the producing instruction is in EX/MEM or MEM/WB and a consuming instruction needs the value:

- **EX-EX forward**: result from EX/MEM register → ALU input
- **MEM-EX forward**: result from MEM/WB register → ALU input

#### Load-Use Hazard — Pipeline Stall
When a load instruction is followed immediately by a dependent instruction:
1. Stall `IF` and `ID` stages for one cycle (hold `IF_ID` and `ID_EX` registers, freeze PC)
2. Insert a NOP bubble into the `EX` stage

#### Control Hazards — Flush on Branch
- Use **predict-not-taken** strategy
- Resolve branches at the end of the EX stage
- On a taken branch: flush the two instructions fetched after the branch (zero out `IF_ID` and `ID_EX` pipeline registers)
- Unconditional jumps (`JAL`, `JALR`) are also resolved at EX; same flush applies

### New/Modified Modules

```
cpu (pipelined)
├── hazard_unit         # detects stalls and generates flush/stall signals
├── forward_unit        # generates forwarding mux select signals
├── if_id_reg           # pipeline register
├── id_ex_reg           # pipeline register
├── ex_mem_reg          # pipeline register
├── mem_wb_reg          # pipeline register
└── (all Phase 1 modules retained)
```

### Deliverables
- Pipelined CPU passing Phase 2 test suite
- Waveform demonstrating correct forwarding and stall behavior for provided test cases
- Brief written explanation (in `docs/hazard_analysis.md`) of how each hazard type is handled

---

## Phase 3 — Extensions (Stretch Goals)

Choose at least one:

### Option A — Static Branch Prediction (Backward-Taken, Forward-Not-Taken)
- Predict backward branches (negative offset) as taken, forward branches as not-taken
- Measure misprediction rate on provided benchmarks

### Option B — Direct-Mapped Instruction Cache
- 256-entry direct-mapped cache, 4-byte cache lines (one word per line)
- Implement hit/miss logic; on miss, stall pipeline and fetch from ROM
- Report hit rate on provided benchmarks

### Option C — Basic Trap Handling
- Implement CSR registers: `mstatus`, `mtvec`, `mepc`, `mcause`
- Support `ECALL` and `EBREAK` instructions
- On trap: save PC to `mepc`, set `mcause`, jump to `mtvec`
- Support `MRET` to return from trap handler

---

## Register File Specification

- 32 general-purpose registers: `x0`–`x31`
- `x0` is hardwired to 0; writes to `x0` are silently ignored
- Synchronous write, asynchronous (combinational) read
- Write occurs on the rising edge of the clock
- Read-during-write: return the new value (forward within register file)

---

## Clocking and Reset

- Single clock domain (`clk`)
- Active-low synchronous reset (`rst_n`)
- On reset: PC ← `32'h0000_0000`, all pipeline registers cleared

---

## Verification

### Toolchain
- Simulation: [Verilator](https://www.veripool.org/verilator/) (preferred) or Vivado XSim
- Assembler: `riscv64-unknown-elf-as` with `-march=rv32i -mabi=ilp32`

### Test Suites

| Phase | Test Suite | Pass Criteria |
|-------|-----------|---------------|
| Phase 1 | `tests/phase1/` — unit tests for each instruction type | All instructions produce correct results in simulation |
| Phase 2 | `tests/phase2/` — hazard sequences, forwarding cases, load-use, branch flush | Correct register values after each sequence; no stale data |
| Phase 3 | `tests/phase3/` — benchmark programs | Defined per chosen extension |

### Compliance
After Phase 2, run the [riscv-arch-test](https://github.com/riscv-non-isa/riscv-arch-test) `rv32i` suite. All tests must pass.

---

## Coding Guidelines

- One module per file; filename matches module name (e.g., `alu.v`, `reg_file.v`)
- Use `parameter` for configurable widths; avoid magic numbers
- Write synthesizable RTL only (no delays, no `initial` blocks outside testbenches)
- All combinational logic in `always @(*)` blocks or continuous assignments
- All sequential logic triggered on `posedge clk`

---

## Grading Rubric

| Component | Points |
|-----------|--------|
| Phase 1: correct single-cycle datapath | 35 |
| Phase 2: pipeline registers + forwarding | 30 |
| Phase 2: stall and flush logic | 20 |
| Phase 3: one stretch goal completed | 10 |
| Code quality and documentation | 5 |
| **Total** | **100** |

---

## Suggested Timeline (4 weeks)

| Week | Milestone |
|------|-----------|
| 1 | Complete Phase 1; all unit tests passing |
| 2 | Add pipeline registers; verify basic instruction sequences |
| 3 | Add forwarding and hazard units; pass Phase 2 test suite |
| 4 | Complete one Phase 3 extension; run compliance tests; write-up |
