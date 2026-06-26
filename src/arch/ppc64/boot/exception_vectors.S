# Copyright 2026 PhoronMC
# Licensed under All Rights Reserved

    .section .exception_vectors, "ax"
    .globl exception_vectors_start

exception_vectors_start:

    .align 8
    .globl vector_0x100
vector_0x100:
    b   exception_common

    .align 8
    .globl vector_0x200
vector_0x200:
    b   exception_common

    .align 8
    .globl vector_0x300
vector_0x300:
    b   exception_common

    .align 8
    .globl vector_0x400
vector_0x400:
    b   exception_common

    .align 8
    .globl vector_0x500
vector_0x500:
    b   exception_common

    .align 8
    .globl vector_0x600
vector_0x600:
    b   exception_common

    .align 8
    .globl vector_0x700
vector_0x700:
    b   exception_common

    .align 8
    .globl vector_0x800
vector_0x800:
    b   exception_common

    .align 8
    .globl vector_0x900
vector_0x900:
    b   exception_common

    .align 8
    .globl exception_common
exception_common:
    bl  interrupt_dispatch
    b   exception_common
