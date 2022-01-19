#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    char *cleared = NULL;
    int len;

    if (!str)
        return NULL;
    while(mx_isspace(*str) == 1)
        str++;
    len = mx_strlen(str);
    for (int i = len - 1; mx_isspace(str[i]) == 1; i--) {
        len--;
    }
        if (len < 0) {
        cleared = mx_strnew(0); 
        return cleared;
    }
    cleared = mx_strnew(len);
    cleared = mx_strncpy(cleared, str, len);
    return cleared;
}

