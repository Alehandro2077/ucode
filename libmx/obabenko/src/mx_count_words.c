#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if(!str) return -1;
    int i = 0, ct = 0, st = 1;

    while(str[i]) {
        if(str[i] == c) {
            st = 1;
        }
        else if(st) {
            st = 0;
            ct++;
        }
        i++;
    }

    return ct;
}


