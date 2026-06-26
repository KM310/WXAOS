/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern void arch_map_page(uint64_t virt, uint64_t phys, uint64_t flags);
extern void arch_paging_init(void);

void paging_init(void) {
    arch_paging_init();
}

void map_page(uint64_t virt, uint64_t phys, uint64_t flags) {
    arch_map_page(virt, phys, flags);
}
