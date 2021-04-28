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
	u16 pc, sp;
	u8 a, b, p;
};
