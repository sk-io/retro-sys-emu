#include "cpu.h"

CPU::CPU() {}

u8 CPU::read(u16 addr) {
	for (auto& c : components) {
		if (c->is_mapped_to(addr))
			return c->read(addr);
	}
	return 255;
}

void CPU::write(u16 addr, u8 data) {
	for (auto& c : components) {
		c->write(addr, data);
	}
}

void CPU::attach(Component& c) {
	components.push_back(&c);
}
