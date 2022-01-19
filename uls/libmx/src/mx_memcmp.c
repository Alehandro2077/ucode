#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    if(n == 0) return 0;

    const uc_t *s1_tmp = s1;
    const uc_t *s2_tmp = s2;

    for(size_t i = 0; *s1_tmp == *s2_tmp && i != n - 1; s1_tmp++, s2_tmp++) {
        if(s2_tmp == '\0') {
            return 0;
        }
        i++;
    }

    return *s1_tmp - *s2_tmp;
}

