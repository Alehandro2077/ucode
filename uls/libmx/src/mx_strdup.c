#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    const char *temp = str; 
    int size = 0;

    while (*temp++)
        size++;

    if (size < 0) return NULL;

    char *newstr = mx_strnew(mx_strlen(str));
    mx_strcpy(newstr, str);

    return newstr;
}


