#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int sz2 = mx_strlen(needle);

    while(*haystack) {
        if(mx_strchr(&(*haystack), needle[0])) {
            if(mx_strncmp(haystack, needle, sz2) == 0) {
                return (char*) haystack;
            }
        }
        haystack++;
    }
    return NULL;
}

