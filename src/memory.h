#pragma once

#include "types.h"

#include "component.h"

class Memory : public Component {
public:
	Memory(u32 size, u32 start_addr, bool rom = false);
	~Memory();

	bool read(u16 addr, u8& data);
	void write(u16 addr, u8 data);

	void put(const char* data, u16 len, u16 start_addr);
private:
	u8* mem = nullptr;
	u32 size = 0, start_addr = 0;
	bool rom = false;
};
