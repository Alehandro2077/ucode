#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
    int i = 0; 

    while(*s1 && *s1 == *s2 && ++i < n) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}


