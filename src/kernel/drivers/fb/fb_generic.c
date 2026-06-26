/* Copyright 2026 PhoronMC
 * Licensed under GPLv3
 */

#include <stdint.h>

struct fb_info {
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint32_t bpp;
    void    *base;
};

extern int  arch_fb_init(struct fb_info *info);
extern void arch_fb_putpixel(struct fb_info *info,
                             uint32_t x, uint32_t y,
                             uint32_t color);
extern void arch_fb_clear(struct fb_info *info, uint32_t color);

static struct fb_info fb;

int fb_init(void) {
    return arch_fb_init(&fb);
}

void fb_clear(uint32_t color) {
    arch_fb_clear(&fb, color);
}

void fb_putpixel(uint32_t x, uint32_t y, uint32_t color) {
    arch_fb_putpixel(&fb, x, y, color);
}

struct fb_info *fb_get_info(void) {
    return &fb;
}
