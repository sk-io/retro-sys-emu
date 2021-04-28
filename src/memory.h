#pragma once

#include "types.h"

#include "component.h"

class Memory : public Component {
public:
	Memory(u32 size, u32 start_addr, bool rom = false);
	~Memory();

	bool read(u16 addr, u8& data);
	void write(u16 addr, u8 data);
private:
	u8* mem;
	u32 size, start_addr;
	bool rom;
};
