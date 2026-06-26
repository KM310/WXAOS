/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern uint64_t arch_physmem_base(void);
extern uint64_t arch_physmem_size(void);

static uint64_t phys_base;
static uint64_t phys_end;
static uint64_t phys_curr;

void physmem_init(void) {
    phys_base = arch_physmem_base();
    phys_end  = phys_base + arch_physmem_size();
    phys_curr = phys_base;
}

uint64_t phys_alloc_page(void) {
    const uint64_t PAGE_SIZE = 4096;

    if (phys_curr + PAGE_SIZE > phys_end)
        return 0;

    uint64_t addr = phys_curr;
    phys_curr += PAGE_SIZE;
    return addr;
}
