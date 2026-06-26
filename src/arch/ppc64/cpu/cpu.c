/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

static inline uint64_t read_spr(uint32_t spr) {
    uint64_t v;
    __asm__ volatile("mfspr %0, %1" : "=r"(v) : "i"(spr));
    return v;
}

uint64_t cpu_get_pvr(void) {
    return read_spr(0x11F);
}

uint64_t cpu_get_timebase(void) {
    uint64_t tbu, tbl;
    __asm__ volatile("mftbu %0" : "=r"(tbu));
    __asm__ volatile("mftb %0"  : "=r"(tbl));
    return (tbu << 32) | tbl;
}

void cpu_init(void) {
    cpu_get_pvr();
    cpu_get_timebase();
}
