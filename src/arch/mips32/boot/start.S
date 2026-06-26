/* start.S - MIPS32 boot code
 * Copyright (c) 2026 PhoronMC
 * All Rights Reserved.
 */

    .section .text.start, "ax"
    .globl _start

_start:
    /* Disable interrupts: clear CP0 Status */
    li      $t0, 0
    mtc0    $t0, $12          # CP0_STATUS
    nop

    /* Set up stack pointer (from linker script) */
    la      $sp, _stack_top

    /* Zero .bss */
    la      $t1, _bss_start
    la      $t2, _bss_end

bss_zero:
    beq     $t1, $t2, bss_done
    nop
    sw      $zero, 0($t1)
    addiu   $t1, $t1, 4
    b       bss_zero
    nop

bss_done:
    /* Jump to kernel_main */
    la      $t3, kernel_main
    jal     $t3
    nop

halt:
    b       halt
    nop
