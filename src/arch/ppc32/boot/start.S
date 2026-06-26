/* start.S - PPC32 boot code
 * Copyright (c) 2026 PhoronMC
 * All Rights Reserved.
 */

    .section .text.start, "ax"
    .globl _start

_start:
    # Interrupts deaktivieren
    mfmsr   r0
    li      r3, 0
    mtmsr   r3
    isync

    # Stackpointer setzen
    lis     r1, _stack_top@ha
    addi    r1, r1, _stack_top@l

    # .bss nullen
    lis     r3, _bss_start@ha
    addi    r3, r3, _bss_start@l

    lis     r4, _bss_end@ha
    addi    r4, r4, _bss_end@l

zero_bss:
    cmpw    r3, r4
    beq     bss_done
    stw     r0, 0(r3)
    addi    r3, r3, 4
    b       zero_bss

bss_done:
    # Kernel starten
    bl      kernel_main

halt:
    b       halt
