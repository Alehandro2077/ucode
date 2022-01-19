#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    uc_t *big_tmp = (uc_t*)big;
    uc_t *l_tmp = (uc_t*)little;

    if(big_len >= little_len && big_len > 0 && little_len > 0) {
        while(*big_tmp) {
            if(mx_memcmp(big_tmp, l_tmp, little_len) == 0) {
                return big_tmp;
            }
            big_tmp++;
        }
    }

    return NULL;
}

