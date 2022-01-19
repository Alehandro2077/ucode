#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if(!str) return NULL;

    int i = 0, j = 0;

    char *new = mx_strnew(mx_strlen(str));

    while(str[i]) {
        if(!mx_isspace(str[i])) {
            new[j++] = str[i];
        }

        if(!mx_isspace(str[i]) && mx_isspace(str[i+1])) {
            new[j++] = ' ';
        }
        i++;
    }

    char *tmp = mx_strtrim(new);
    mx_strdel(&new);

    return tmp;
}

