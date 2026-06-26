/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern void interrupt_register(uint32_t vec, void (*handler)(void));

static inline void write_dec(uint64_t v) {
    __asm__ volatile("mtdec %0" :: "r"(v));
}

static inline uint64_t read_tb(void) {
    uint64_t tbu, tbl;
    __asm__ volatile("mftbu %0" : "=r"(tbu));
    __asm__ volatile("mftb %0"  : "=r"(tbl));
    return (tbu << 32) | tbl;
}

static void decrementer_handler(void) {
    write_dec(1000000);
}

void decrementer_init(void) {
    interrupt_register(0x900, decrementer_handler);
    write_dec(1000000);
}
