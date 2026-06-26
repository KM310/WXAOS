/* start.S - ARM32 (AArch32) boot code
 * Copyright (c) 2026 PhoronMC
 * All Rights Reserved.
 */

    .section .text.start, "ax"
    .globl _start

_start:
    /* In Supervisor Mode wechseln (falls nicht schon) */
    mrs r0, cpsr
    bic r0, r0, #0x1F
    orr r0, r0, #0x13        /* SVC mode */
    msr cpsr_c, r0

    /* Interrupts deaktivieren */
    cpsid if

    /* Stackpointer setzen */
    ldr r0, =_stack_top
    mov sp, r0

    /* .bss nullen */
    ldr r1, =_bss_start
    ldr r2, =_bss_end

bss_zero:
    cmp r1, r2
    beq bss_done
    mov r3, #0
    str r3, [r1], #4
    b bss_zero

bss_done:
    /* Kernel starten */
    bl kernel_main

halt:
    wfi
    b halt
