/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern void context_switch_asm(void *old_ctx, void *new_ctx);

void context_switch(void *old_ctx, void *new_ctx) {
    context_switch_asm(old_ctx, new_ctx);
}
