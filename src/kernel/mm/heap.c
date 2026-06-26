/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern void *arch_heap_base(void);
extern uint64_t arch_heap_size(void);

static uint8_t *heap_ptr;
static uint8_t *heap_end;

void heap_init(void) {
    heap_ptr = (uint8_t *)arch_heap_base();
    heap_end = heap_ptr + arch_heap_size();
}

void *kmalloc(uint64_t size) {
    if (!heap_ptr)
        return 0;

    uint64_t aligned = (size + 7) & ~7ULL;

    if (heap_ptr + aligned > heap_end)
        return 0;

    void *res = heap_ptr;
    heap_ptr += aligned;
    return res;
}
