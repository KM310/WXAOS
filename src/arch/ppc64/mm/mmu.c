/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern uint64_t __pgd_base;

static inline void write_spr(uint32_t spr, uint64_t val) {
    __asm__ volatile("mtspr %0, %1" :: "i"(spr), "r"(val));
}

static inline uint64_t read_msr(void) {
    uint64_t v;
    __asm__ volatile("mfmsr %0" : "=r"(v));
    return v;
}

static inline void write_msr(uint64_t v) {
    __asm__ volatile("mtmsr %0; isync" :: "r"(v));
}

void mmu_init(void) {
    write_spr(0x3F0, (uint64_t)&__pgd_base);

    uint64_t msr = read_msr();
    msr |= (1ULL << 58);
    msr |= (1ULL << 57);
    write_msr(msr);

    __asm__ volatile("ptesync; tlbsync; eieio");
}
