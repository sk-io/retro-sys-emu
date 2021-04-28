#include "cpu6502.h"

void CPU6502::reset() {
	sp = 0;
	a = b = p = 0;

	pc = (u16)read(0xFFFC);
	pc |= ((u16)read(0xFFFD)) << 8;
}

void CPU6502::clock() {
	pc++;
}
