# Copyright 2026 PhoronMC
# Licensed under All Rights Reserved

    .section .text.crt0, "ax"
    .globl _crt0_entry

_crt0_entry:
    bl      __init_array_start
    bl      kernel_main

1:
    b       1b
