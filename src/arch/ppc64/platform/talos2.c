/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern void uart_puts(const char *s);
extern void decrementer_init(void);
extern void interrupts_init(void);
extern void cpu_init(void);

void platform_init(void) {
    cpu_init();
    uart_puts("Talos II platform\n");
    interrupts_init();
    decrementer_init();
}
