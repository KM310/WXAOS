# Copyright 2026 PhoronMC
# Licensed under All Rights Reserved

    .section .text.early_uart, "ax"
    .globl early_uart_putc
    .globl early_uart_puts

UART_BASE = 0xF0004500
UART_THR  = 0x00
UART_LSR  = 0x05

early_uart_putc:
    lis     r4, UART_BASE@ha
    addi    r4, r4, UART_BASE@l

1:
    lbz     r5, UART_LSR(r4)
    rlwinm  r6, r5, 0, 31, 31
    cmpwi   r6, 0
    beq     1b

    stb     r3, UART_THR(r4)
    blr

early_uart_puts:
    cmpwi   r3, 0
    beq     3f

2:
    lbz     r4, 0(r3)
    cmpwi   r4, 0
    beq     3f
    mr      r5, r4
    mr      r3, r5
    bl      early_uart_putc
    addi    r3, r3, 1
    b       2b

3:
    blr
