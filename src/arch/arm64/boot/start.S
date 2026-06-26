/* start.S - ARM64 (AArch64) boot code
 * Copyright (c) 2026 PhoronMC
 * All Rights Reserved.
 */

    .section .text.start, "ax"
    .globl _start

_start:
    // EL1 assumed. Disable interrupts.
    msr daifset, #0xF

    // Set stack pointer (from linker script)
    ldr x0, =_stack_top
    mov sp, x0

    // Zero .bss
    ldr x1, =_bss_start
    ldr x2, =_bss_end

bss_zero:
    cmp x1, x2
    b.eq bss_done
    str xzr, [x1], #8
    b bss_zero

bss_done:
    // Call kernel_main()
    bl kernel_main

halt:
    wfe
    b halt
