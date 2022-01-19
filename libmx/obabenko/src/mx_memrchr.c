#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    uc_t *tmp = (uc_t*)s;

    for(size_t i = n - 1; i; i--) {
        if(tmp[i] == c) {
            return &(tmp[i]);
        }
    }

    return NULL;
}

