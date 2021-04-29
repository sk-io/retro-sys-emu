#pragma once

#include "cpu.h"

class CPU6502 : public CPU {
public:
	void reset();
	void clock();

	u16 get_pc() {
		return pc;
	}
private:
	u32 cycles = 0;
	u16 pc = 0, sp = 0;
	u8 a = 0, b = 0, p = 0;
};
