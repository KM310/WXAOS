/* printf.c - Minimal kernel printf implementation
 * Copyright 2026 PhoronMC
 * Licensed under LGPLv3
 */

#include <stdint.h>
#include <stdarg.h>

extern void uart_write_char(char c);
extern void uart_write(const char *s);

static void print_uint(uint64_t v, int base) {
    char buf[32];
    const char *digits = "0123456789abcdef";
    int i = 0;

    if (v == 0) {
        uart_write_char('0');
        return;
    }

    while (v > 0) {
        buf[i++] = digits[v % base];
        v /= base;
    }

    while (i--)
        uart_write_char(buf[i]);
}

static void print_int(int64_t v) {
    if (v < 0) {
        uart_write_char('-');
        v = -v;
    }
    print_uint((uint64_t)v, 10);
}

void printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    while (*fmt) {
        if (*fmt != '%') {
            uart_write_char(*fmt++);
            continue;
        }

        fmt++;

        switch (*fmt) {
            case 's': {
                const char *s = va_arg(args, const char *);
                uart_write(s);
                break;
            }
            case 'c': {
                char c = (char)va_arg(args, int);
                uart_write_char(c);
                break;
            }
            case 'd':
            case 'i': {
                int64_t v = va_arg(args, int64_t);
                print_int(v);
                break;
            }
            case 'u': {
                uint64_t v = va_arg(args, uint64_t);
                print_uint(v, 10);
                break;
            }
            case 'x': {
                uint64_t v = va_arg(args, uint64_t);
                print_uint(v, 16);
                break;
            }
            case 'p': {
                uint64_t v = va_arg(args, uint64_t);
                uart_write("0x");
                print_uint(v, 16);
                break;
            }
            case '%':
                uart_write_char('%');
                break;
        }

        fmt++;
    }

    va_end(args);
}
