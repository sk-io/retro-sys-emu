#include "cpu6502.h"

void CPU6502::reset() {
	sp = 0;
	a = b = p = 0;
}

void CPU6502::clock() {
	pc++;
}
