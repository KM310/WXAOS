/* start.S - x86_64 boot code
 * Copyright (c) 2026 PhoronMC
 * All Rights Reserved.
 */

    .section .text.start, "ax"
    .globl _start

_start:
    cli                         # Interrupts deaktivieren

    # Stackpointer setzen (vom Linker-Script)
    mov $_stack_top, %rsp

    # .bss nullen
    mov $_bss_start, %rdi
    mov $_bss_end,   %rcx
    sub %rdi, %rcx              # rcx = size in bytes
    xor %rax, %rax

bss_zero:
    cmp $0, %rcx
    je  bss_done
    mov %rax, (%rdi)
    add $8, %rdi
    sub $8, %rcx
    jmp bss_zero

bss_done:
    # kernel_main aufrufen
    call kernel_main

halt:
    hlt
    jmp halt
