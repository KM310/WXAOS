/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern void uart_puts(const char *s);
extern void platform_init(void);

void kernel_main(void) {
    platform_init();
    uart_puts("Kernel main reached\n");

    while (1) {
        __asm__ volatile("nop");
    }
}
