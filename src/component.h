#pragma once

#include "types.h"

class Component {
public:
	Component();

	virtual bool read(u16 addr, u8& data) = 0;
	virtual void write(u16 addr, u8 data) = 0;
};
