#include "ram.h"

RAM::RAM(u32 size, u32 start_addr) {
}

bool RAM::is_mapped_to(u16 addr) {
    return false;
}

u8 RAM::read(u16 addr) {
    return u8();
}

void RAM::write(u16 addr, u8 data) {
}
