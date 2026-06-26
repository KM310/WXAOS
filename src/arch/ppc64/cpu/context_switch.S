# Copyright 2026 PhoronMC
# Licensed under GPLv3

    .section .text.context_switch, "ax"
    .globl context_switch

context_switch:
    std     r0,   0(r3)
    std     r1,   8(r3)
    std     r2,  16(r3)
    std     r3,  24(r3)
    std     r4,  32(r3)
    std     r5,  40(r3)
    std     r6,  48(r3)
    std     r7,  56(r3)
    std     r8,  64(r3)
    std     r9,  72(r3)
    std     r10, 80(r3)
    std     r11, 88(r3)
    std     r12, 96(r3)
    std     r13,104(r3)
    std     r14,112(r3)
    std     r15,120(r3)
    std     r16,128(r3)
    std     r17,136(r3)
    std     r18,144(r3)
    std     r19,152(r3)
    std     r20,160(r3)
    std     r21,168(r3)
    std     r22,176(r3)
    std     r23,184(r3)
    std     r24,192(r3)
    std     r25,200(r3)
    std     r26,208(r3)
    std     r27,216(r3)
    std     r28,224(r3)
    std     r29,232(r3)
    std     r30,240(r3)
    std     r31,248(r3)

    mflr    r0
    std     r0, 256(r3)
    mfctr   r0
    std     r0, 264(r3)
    mfcr    r0
    std     r0, 272(r3)
    mfxer   r0
    std     r0, 280(r3)

    ld      r0,   0(r4)
    ld      r1,   8(r4)
    ld      r2,  16(r4)
    ld      r3,  24(r4)
    ld      r4,  32(r4)
    ld      r5,  40(r4)
    ld      r6,  48(r4)
    ld      r7,  56(r4)
    ld      r8,  64(r4)
    ld      r9,  72(r4)
    ld      r10, 80(r4)
    ld      r11, 88(r4)
    ld      r12, 96(r4)
    ld      r13,104(r4)
    ld      r14,112(r4)
    ld      r15,120(r4)
    ld      r16,128(r4)
    ld      r17,136(r4)
    ld      r18,144(r4)
    ld      r19,152(r4)
    ld      r20,160(r4)
    ld      r21,168(r4)
    ld      r22,176(r4)
    ld      r23,184(r4)
    ld      r24,192(r4)
    ld      r25,200(r4)
    ld      r26,208(r4)
    ld      r27,216(r4)
    ld      r28,224(r4)
    ld      r29,232(r4)
    ld      r30,240(r4)
    ld      r31,248(r4)

    ld      r0, 256(r4)
    mtlr    r0
    ld      r0, 264(r4)
    mtctr   r0
    ld      r0, 272(r4)
    mtcr    r0
    ld      r0, 280(r4)
    mtxer   r0

    blr
