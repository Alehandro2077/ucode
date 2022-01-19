#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
    if(!str || !*str) return -2;

    int len = mx_strlen(str);
    int i = 0;

    while(*str) {
        if(*str == c) {
            break;
        }
        i++;
        str++;
    }
    if(i >= len) return -1;

    return i;
}

