#pragma once

#include <vector>

#include "component.h"

class CPU {
public:
	CPU();

	virtual void reset() = 0;
	virtual void clock() = 0;

	void attach(Component& c);
protected:
	u8 read(u16 addr);
	void write(u16 addr, u8 data);

	std::vector<Component*> components;
};
