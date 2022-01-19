#include "../inc/uls.h"

void mx_spaces(char *str, int maxl) {
    int len = mx_strlen(str);

    for(int i = 0; i < maxl - len; i++) {
        mx_printchar(' ');
    }
}

int get_maxlen(char ***arr_str, int in, int size) {
    int max = 0;
    int len = 0;

    for(int i = 0; i < size; i++) {
        len = mx_strlen(arr_str[i][in]);
        if(len > max) {
            max = len;
        }
    }

    return max;
}



void mx_col_print_l(t_list *list) {
    t_list *cur = list;
    int parts = 0;
    int *sizes;      ///////
    char ***splited_name;     /////
    int sz_list = mx_list_size(list);

    if(!list) {
        return;
    }

    splited_name = malloc(sz_list * sizeof (*splited_name));      ///////////??????

    for(int i = 0; i < sz_list; i++) {
        splited_name[i] = mx_strsplit(cur->data, ' ');

        cur = cur->next;
    }

    for(int i = 0; splited_name[0][i]; i++) {      /////////////////
        parts++;
    }

    sizes = malloc(parts * sizeof(*sizes));

    for(int i = 0; i < 8; i++) {
        sizes[i] = get_maxlen(splited_name, i, sz_list);
    }

    cur = list;

    for(int i = 0; i < sz_list; i++) {

        for(int j = 0; j < parts; j++) {
            if(!splited_name[i][j]) {
                mx_printchar('\n');
                break;
            }

            if(j == 5) {
                mx_printstr(mx_strstr(cur->data, splited_name[i][j]));
                mx_printchar('\n');
                break;
            }

            if(j == 0 || j == 2 || j == 3) {
                mx_printstr(splited_name[i][j]);
                mx_spaces(splited_name[i][j], sizes[j]);
                mx_printstr("  ");
                continue;
            }
            if(mx_isdigit(splited_name[i][j][0])) {
                mx_spaces(splited_name[i][j], sizes[j]);
                mx_printstr(splited_name[i][j]);
                mx_printchar(' ');
            }

        }
        mx_strdel((char**)&cur->data);
        cur = cur->next;
        mx_del_strarr(&splited_name[i]);
    }

    free(sizes);
    free(splited_name);
}

