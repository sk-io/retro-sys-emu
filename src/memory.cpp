#include "memory.h"

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

    data = mem[i];
}
