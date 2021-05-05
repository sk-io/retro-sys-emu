#pragma once

#include "cpu.h"

class CPU6502 : public CPU {
public:
	CPU6502();

	void reset();
	void clock();

	u8 get_cycles() { return cycles; }
	u16 get_pc() { return pc; }
	u8 get_a() { return a; }

	struct Instruction {
		u8 func;
		u8 adr_mode;
		u8 cycles;
	};
private:
	enum {
		UNK,
		IMP,
		IMM,
		ZP0,
		ZPX,
	};
	enum {
		//UNK,
		LDA = 1,
		ADC,
	};

	static Instruction instructions[256];

	u8 instr;
	u8 instr_cycles_left;

	u32 cycles = 0;
	u16 pc = 0, sp = 0;
	u8 a = 0, b = 0, p = 0;

	void exec_instr();
	u8 next_byte();
};
