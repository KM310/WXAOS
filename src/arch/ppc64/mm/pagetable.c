/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

#define PTE_VALID   (1ULL << 0)
#define PTE_LEAF    (1ULL << 1)
#define PTE_READ    (1ULL << 2)
#define PTE_WRITE   (1ULL << 3)
#define PTE_EXEC    (1ULL << 4)

uint64_t __pgd_base[512] __attribute__((aligned(4096)));

static inline void set_pte(uint64_t *entry, uint64_t phys) {
    *entry = phys | PTE_VALID | PTE_LEAF | PTE_READ | PTE_WRITE | PTE_EXEC;
}

void pagetable_identity_map(uint64_t virt, uint64_t phys) {
    uint64_t index = (virt >> 39) & 0x1FF;
    set_pte(&__pgd_base[index], phys);
}

void pagetable_init(void) {
    pagetable_identity_map(0x0000000000000000ULL, 0x0000000000000000ULL);
}
