#pragma once

#include "types.h"

class Component {
public:
	Component();

	virtual bool is_mapped_to(u16 addr) = 0;
	virtual u8 read(u16 addr) = 0;
	virtual void write(u16 addr, u8 data) = 0;
};
