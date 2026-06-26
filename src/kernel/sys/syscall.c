/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

#define MAX_SYSCALLS 64

static uint64_t (*syscalls[MAX_SYSCALLS])(uint64_t, uint64_t, uint64_t, uint64_t);

void syscall_register(uint64_t num, uint64_t (*fn)(uint64_t, uint64_t, uint64_t, uint64_t)) {
    if (num < MAX_SYSCALLS)
        syscalls[num] = fn;
}

uint64_t syscall_handle(uint64_t num, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    if (num < MAX_SYSCALLS && syscalls[num])
        return syscalls[num](a0, a1, a2, a3);

    return (uint64_t)-1;
}
