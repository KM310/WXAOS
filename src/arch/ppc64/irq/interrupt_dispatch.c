/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern void interrupt_handle(uint32_t vec);

static inline uint64_t read_srr1(void) {
    uint64_t v;
    __asm__ volatile("mfsrr1 %0" : "=r"(v));
    return v;
}

uint32_t interrupt_decode_vector(void) {
    uint64_t srr1 = read_srr1();
    return (srr1 >> 42) & 0x1F;
}

void interrupt_dispatch(void) {
    uint32_t vec = interrupt_decode_vector();
    interrupt_handle(vec);
}
