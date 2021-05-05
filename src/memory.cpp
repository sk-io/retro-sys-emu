#include "memory.h"

#include <string.h>

Memory::Memory(u32 _size, u32 _start_addr, bool _rom) : 
    size(_size), start_addr(_start_addr), rom(_rom) {
    mem = new u8[_size];
}

Memory::~Memory() {
    delete[] mem;
}

bool Memory::read(u16 addr, u8& data) {
    int i = addr - start_addr;
    if (i < 0 || i >= size)
        return false;

    data = mem[i];
    return true;
}

void Memory::write(u16 addr, u8 data) {
    if (rom)
        return;

    int i = addr - start_addr;
    if (i < 0 || i >= size)
        return;

    mem[i] = data;
}

void Memory::put(const char* data, u16 len, u16 start_addr) {
    memcpy(mem + start_addr, data, len);
}
