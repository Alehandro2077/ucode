#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if(!str || !sub) return -1;

    int sub_len = mx_strlen(sub);

    if(!sub_len) return 0;

    int ct = 0;

    if(mx_strlen(str) > sub_len) {
        while (*str){
            if (mx_strncmp(str, sub, sub_len) == 0){
                ct++;
            }
            str++;
        }
    }

    return ct;
}

