/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

static inline void tlb_flush_all(void) {
    __asm__ volatile("ptesync; tlbsync; eieio");
}

static inline void tlb_invalidate(uint64_t addr) {
    __asm__ volatile("tlbie %0; ptesync; eieio" :: "r"(addr));
}

void tlb_init(void) {
    tlb_flush_all();
}
