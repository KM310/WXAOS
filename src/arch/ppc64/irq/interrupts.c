/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

#define MAX_INTERRUPTS 256

static void (*interrupt_handlers[MAX_INTERRUPTS])(void);

static inline uint64_t read_msr(void) {
    uint64_t v;
    __asm__ volatile("mfmsr %0" : "=r"(v));
    return v;
}

static inline void write_msr(uint64_t v) {
    __asm__ volatile("mtmsr %0; isync" :: "r"(v));
}

void interrupts_enable(void) {
    uint64_t msr = read_msr();
    msr |= (1ULL << 48);
    write_msr(msr);
}

void interrupts_disable(void) {
    uint64_t msr = read_msr();
    msr &= ~(1ULL << 48);
    write_msr(msr);
}

void interrupt_register(uint32_t vec, void (*handler)(void)) {
    if (vec < MAX_INTERRUPTS)
        interrupt_handlers[vec] = handler;
}

void interrupt_handle(uint32_t vec) {
    if (vec < MAX_INTERRUPTS && interrupt_handlers[vec])
        interrupt_handlers[vec]();
}

void interrupts_init(void) {
    for (int i = 0; i < MAX_INTERRUPTS; i++)
        interrupt_handlers[i] = 0;

    interrupts_enable();
}
