/* string.c - Generic string/memory functions
 * Copyright 2026 PhoronMC
 * Licensed under LGPLv3
 */

#include <stdint.h>

void *memcpy(void *dst, const void *src, uint64_t n) {
    uint8_t *d = dst;
    const uint8_t *s = src;

    for (uint64_t i = 0; i < n; i++)
        d[i] = s[i];

    return dst;
}

void *memset(void *dst, int value, uint64_t n) {
    uint8_t *d = dst;

    for (uint64_t i = 0; i < n; i++)
        d[i] = (uint8_t)value;

    return dst;
}

int memcmp(const void *a, const void *b, uint64_t n) {
    const uint8_t *x = a;
    const uint8_t *y = b;

    for (uint64_t i = 0; i < n; i++) {
        if (x[i] != y[i])
            return x[i] - y[i];
    }

    return 0;
}

uint64_t strlen(const char *s) {
    uint64_t len = 0;
    while (s[len])
        len++;
    return len;
}

char *strcpy(char *dst, const char *src) {
    uint64_t i = 0;
    while ((dst[i] = src[i]))
        i++;
    return dst;
}

int strcmp(const char *a, const char *b) {
    while (*a && (*a == *b)) {
        a++;
        b++;
    }
    return (unsigned char)*a - (unsigned char)*b;
}
