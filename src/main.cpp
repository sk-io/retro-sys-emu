#include <iostream>

#include "types.h"
#include "cpu6502.h"
#include "memory.h"

int main() {
	CPU6502 cpu;

	Memory ram(0x10000, 0);
	ram.put("\x00\x00", 2, 0xFFFC);
	ram.write(0x0000, 0xA9); // lda
	ram.write(0x0001, 123); // #0x66
	cpu.attach(ram);

	cpu.reset();
	std::cout << "reset vector: " << std::hex << std::uppercase << cpu.get_pc() << std::endl;

	printf("pc: %u cycles: %u a: %u\n", cpu.get_pc(), cpu.get_cycles(), cpu.get_a());
	for (int i = 0; i < 50; i++) {
		cpu.clock();
		if (cpu.get_cycles() >= 2)
			break;
	}

	printf("pc: %u cycles: %u a: %u\n", cpu.get_pc(), cpu.get_cycles(), cpu.get_a());
	system("pause");
}
