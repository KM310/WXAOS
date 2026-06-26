/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

ENTRY(_start)

SECTIONS
{
    /* Kernel load address */
    . = 0x0000000000000000;

    /* Boot entry + low-level init */
    .text.start : {
        *(.text.start)
    }

    /* Exception vectors (0x100, 0x200, …) */
    .exception_vectors ALIGN(0x1000) : {
        *(.exception_vectors)
    }

    /* Normal kernel code */
    .text ALIGN(0x1000) : {
        *(.text)
        *(.text.*)
    }

    /* Read-only data */
    .rodata ALIGN(0x1000) : {
        *(.rodata)
        *(.rodata.*)
    }

    /* Initialised globals */
    .data ALIGN(0x1000) : {
        *(.data)
        *(.data.*)
    }

    /* Uninitialised globals */
    _bss_start = .;
    .bss ALIGN(0x1000) : {
        *(.bss)
        *(.bss.*)
        *(COMMON)
    }
    _bss_end = .;

    /* Radix MMU root page table */
    .pgtable ALIGN(0x1000) : {
        __pgd_base = .;
        *(.pgtable)
    }

    /* Kernel stack */
    . = ALIGN(0x1000);
    _stack_top = . + 0x40000;
}
