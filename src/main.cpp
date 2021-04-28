#include <iostream>

#include "types.h"
#include "cpu6502.h"
#include "ram.h"

int main() {
	CPU6502 cpu;

	RAM ram(0x1000, 0);
	cpu.attach(ram);

	cpu.reset();

	for (int i = 0; i < 1000; i++) {
		cpu.clock();
	}
}
