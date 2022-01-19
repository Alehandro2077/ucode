#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    uc_t *tmp = (uc_t*)malloc(sizeof(uc_t) * len);

    tmp = mx_memcpy(tmp, src, len);
    dst = mx_memcpy(dst, tmp, len);

    free(tmp);
    tmp = NULL;

    return dst;
}

