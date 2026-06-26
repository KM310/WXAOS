/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern void arch_timer_init(void);
extern void arch_timer_enable(void);
extern void arch_timer_disable(void);

static void (*tick_callback)(void) = 0;

void timer_register_callback(void (*cb)(void)) {
    tick_callback = cb;
}

void timer_tick(void) {
    if (tick_callback)
        tick_callback();
}

void timer_init(void) {
    arch_timer_init();
    arch_timer_enable();
}
