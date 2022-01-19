#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    size_t len = malloc_size(ptr);
    unsigned char *tmp = NULL;

    if ((int)size >= 0) {
        if (size != 0 && size < len)
            return ptr;
        tmp = malloc(size);
        if (size != 0 && ptr != NULL)
            tmp = mx_memcpy(tmp, ptr, size);
        free(ptr);
    }
    return tmp;
}

