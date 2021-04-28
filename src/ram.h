#pragma once

#include "types.h"

#include "component.h"

class RAM : public Component {
public:
	RAM(u32 size, u32 start_addr);

	bool is_mapped_to(u16 addr);
	u8 read(u16 addr);
	void write(u16 addr, u8 data);
};
