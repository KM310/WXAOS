/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern void uart_puts(const char *s);

void panic(const char *msg) {
    uart_puts("Kernel panic: ");
    uart_puts(msg);
    uart_puts("\n");

    while (1) {
        __asm__ volatile("nop");
    }
}
