/* Licensed under GPlv3 */
ENTRY(_start)

SECTIONS
{
    . = 0x0000000000000000;

    .code.start : {
        *(.code.start)
    }

    .exception_vectors : ALIGN(0x1000) {
        *(.exception_vectors)
    }

    .code : ALIGN(0x1000) {
        *(.code)
        *(.code.*)
    }

    .rodata : ALIGN(0x1000) {
        *(.rodata)
        *(.rodata.*)
    }

    .data : ALIGN(0x1000) {
        *(.data)
        *(.data.*)
    }

    _bss_start = .;
    .bss : ALIGN(0x1000) {
        *(.bss)
        *(.bss.*)
        *(COMMON)
    }
    _bss_end = .;

    .pgtable ALIGN(0x1000) : {
        __pgd_base = .;
        *(.pgtable)
    }

    . = ALIGN(0x1000);
    _stack_top = . + 0x40000;
}
