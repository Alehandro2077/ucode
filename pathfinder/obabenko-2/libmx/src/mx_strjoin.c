#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if(!s1 && !s2) return NULL;
    else if(!s1 && s2) {
        return mx_strdup(s2);
    }
    else if(!s2 && s1) {
        return mx_strdup(s1);
    }
    else {
        char *res = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        res = mx_strcpy(res, s1);
        res = mx_strcat(res, s2);
        return res; 
    }
}

