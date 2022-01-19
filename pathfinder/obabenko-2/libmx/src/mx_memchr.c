#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    uc_t *tmp = (uc_t*)s;

    for(size_t i = 0; i < n; i++) {
        if(tmp[i] == c) {
            return tmp + i;
        }
    }

    return NULL;
}

