/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

#define UART_BASE 0xF0004500
#define UART_RBR  0x00
#define UART_THR  0x00
#define UART_LSR  0x05

static inline uint8_t mmio_read8(uint64_t addr) {
    return *(volatile uint8_t *)(addr);
}

static inline void mmio_write8(uint64_t addr, uint8_t val) {
    *(volatile uint8_t *)(addr) = val;
}

void uart_putc(char c) {
    while (!(mmio_read8(UART_BASE + UART_LSR) & 0x20));
    mmio_write8(UART_BASE + UART_THR, c);
}

char uart_getc(void) {
    while (!(mmio_read8(UART_BASE + UART_LSR) & 0x01));
    return mmio_read8(UART_BASE + UART_RBR);
}

void uart_puts(const char *s) {
    while (*s)
        uart_putc(*s++);
}
