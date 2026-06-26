/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

extern void context_switch(void *old_ctx, void *new_ctx);

struct cpu_context {
    uint64_t gpr[32];
    uint64_t lr;
    uint64_t ctr;
    uint64_t cr;
    uint64_t xer;
};

struct task {
    struct cpu_context ctx;
    int active;
};

#define MAX_TASKS 8

static struct task tasks[MAX_TASKS];
static int current = 0;

void scheduler_init(void) {
    for (int i = 0; i < MAX_TASKS; i++)
        tasks[i].active = 0;

    tasks[0].active = 1;
}

int scheduler_create(void (*entry)(void)) {
    for (int i = 1; i < MAX_TASKS; i++) {
        if (!tasks[i].active) {
            tasks[i].active = 1;

            for (int r = 0; r < 32; r++)
                tasks[i].ctx.gpr[r] = 0;

            tasks[i].ctx.lr = (uint64_t)entry;
            tasks[i].ctx.ctr = 0;
            tasks[i].ctx.cr = 0;
            tasks[i].ctx.xer = 0;

            return i;
        }
    }
    return -1;
}

void scheduler_switch(void) {
    int next = (current + 1) % MAX_TASKS;

    while (!tasks[next].active)
        next = (next + 1) % MAX_TASKS;

    int old = current;
    current = next;

    context_switch(&tasks[old].ctx, &tasks[next].ctx);
}

void scheduler_tick(void) {
    scheduler_switch();
}
