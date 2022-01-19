#include "../inc/libmx.h" 

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace || (mx_strlen(str) <= mx_strlen(sub)))
    {
        return NULL;
    }

    int d = mx_strlen(replace) - mx_strlen(sub);
    int len = mx_strlen(str) + mx_count_substr(str, sub) * d;
    char *mem = mx_strnew(len);
    int condition = 0;

    for (int i = 0; i < len; i++, str++)
    {
        condition = 0;
        if (!mx_strncmp((char *)str, (char *)sub, mx_strlen(sub)))
        {
            str += mx_strlen(sub);
            for (int j = 0; j < mx_strlen(replace); i++, j++)
            {
                mem[i] = replace[j];
            }
            condition = 1;
        }
        mem[i] = *str;
        if (condition)
        {
            str--;
            i--;
        }
    }
    return mem;
}

