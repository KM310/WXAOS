/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern void arch_uart_putc(char c);
extern void arch_uart_puts(const char *s);
extern char arch_uart_getc(void);

void uart_write_char(char c) {
    arch_uart_putc(c);
}

void uart_write(const char *s) {
    arch_uart_puts(s);
}

char uart_read_char(void) {
    return arch_uart_getc();
}
