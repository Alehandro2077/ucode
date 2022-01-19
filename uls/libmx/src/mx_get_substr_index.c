#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if(!str || !sub) return -2;

    int sz_sub = mx_strlen(sub);
    int ct = 0;
    while(*str) {
        if(mx_strncmp(str, sub, sz_sub) == 0) {
            return ct;
        }
        str++;
        ct++;
    }

    return -1;
}

