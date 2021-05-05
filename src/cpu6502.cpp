#include "cpu6502.h"

#include <stdio.h>

CPU6502::Instruction CPU6502::instructions[256] = {
//   0             1             2             3             4             5             6             7             8             9             A             B             C             D             E             F
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // 0
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // 1
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // 2
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // 3
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // 4
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // 5
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // 6
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // 7
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // 8
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // 9
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{LDA, IMM, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // A
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // B
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // C
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // D
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // E
	{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2},{UNK, UNK, 2}, // F
};

CPU6502::CPU6502() {
}

void CPU6502::reset() {
	sp = 0;
	a = b = p = 0;
	pc = 0;
	cycles = 0;

	pc = (u16)read(0xFFFC) | ((u16)read(0xFFFD)) << 8;
}

void CPU6502::clock() {
	if (instr_cycles_left == 0) {
		// fetch/exec next instr
		exec_instr();
	}
	instr_cycles_left--;
	cycles++;
}

void CPU6502::exec_instr() {
	instr = next_byte();

	const auto& i = instructions[instr];
	instr_cycles_left = i.cycles;
	
	u8 data = 0b10101010;
	u16 addr = 0b1010101010101010;
	switch (i.adr_mode) {
	case IMP:
		data = a;
		break;
	case IMM:
		data = next_byte();
		break;
	case ZP0:
		addr = (u16) next_byte();
		data = read(addr);
		break;
	case UNK:
	default:
		printf("unknown address mode %i!\n", i.adr_mode);
		break;
	}

	switch (i.func) {
	case LDA:
		a = data;
		break;
	case ADC:
		a += data;
		break;
	case UNK:
	default:
		printf("unknown instruction %i!\n", i.func);
		break;
	}
}

u8 CPU6502::next_byte() {
	return read(pc++);
}
