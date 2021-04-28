#include <iostream>

#include "types.h"
#include "cpu6502.h"
#include "memory.h"

int main() {
	CPU6502 cpu;

	Memory ram(0x10000, 0);
	ram.write(0xFFFC, 0xAB);
	ram.write(0xFFFD, 0xCD);
	cpu.attach(ram);

	cpu.reset();
	std::cout << "reset vector: " << cpu.get_pc() << std::endl;

	for (int i = 0; i < 1000; i++) {
		cpu.clock();
	}

	system("pause");
}
