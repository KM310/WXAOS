/* start.S - x86 32-bit boot code
 * Copyright (c) 2026 PhoronMC
 * All Rights Reserved.
 */

    .section .text.start, "ax"
    .globl _start

_start:
    cli                     # Interrupts deaktivieren

    # Stack setzen (vom Linker-Script)
    mov $(_stack_top), %esp

    # .bss nullen
    mov $(_bss_start), %edi
    mov $(_bss_end),   %ecx
    sub %edi, %ecx             # ecx = size
    xor %eax, %eax

bss_zero:
    cmp $0, %ecx
    je bss_done
    mov %eax, (%edi)
    add $4, %edi
    sub $4, %ecx
    jmp bss_zero

bss_done:
    # kernel_main aufrufen
    call kernel_main

halt:
    hlt
    jmp halt
