/* Licensed Under GPLv3 Copyright 2026 PhoronMC */

SECTIONS {
    . = 0x00000000;

    .text : {
        _start = .;
        *(.text.start)
        *(.text*)
    }

    .bss : {
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        _bss_end = .;
    }

    .stack (NOLOAD) : {
        _stack_bottom = .;
        . = . + 0x4000; /* 16 KiB Stack */
        _stack_top = .;
    }
}
