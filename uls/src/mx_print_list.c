#include "../inc/uls.h"

void mx_print_list(t_list *list) {
    char ***print;
    int elem = mx_list_size(list);
    int c = 0;
    int r = 0;
    int t = 0;
    int max_len = 0;
    int len_cur = 0;

    t_list *cur = list;

    if(!elem) {
        return;
    }

    if(!isatty(STDOUT_FILENO)) {
        while(cur) {
            mx_printstr(cur->data);
            mx_printchar('\n');
            mx_strdel((char**)&cur->data);
            cur = cur->next;
        }
        return;
    }

    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    while(cur) {
        len_cur = mx_strlen(cur->data);
        if(len_cur > max_len) {
            max_len = len_cur;
        }

        cur = cur->next;
    }

    c = w.ws_col / ((max_len / 8 + 1) * 8);

    r = elem / c;

    if((elem % c) == 0) {        ///////////////??????????
        r += 0;
    }
    else {
        r += 1;
    }

    print = malloc(c * sizeof(*print));

    cur = list;

    for(int i = 0; i < c; i++) {
        print[i] = malloc(r * sizeof(**print));

        for(int j = 0; j < r; j++) {
            if(cur) {
                print[i][j] = cur->data;
                cur = cur->next;
            }
            else {
                print[i][j] = NULL;
            }
        }
    }

    for(int j = 0; j < r; j++) {
        for(int i = 0; i < c; i++) {
            if(print[i][j] == NULL) {
                break;
            }

            mx_printstr(print[i][j]);

            if(i + 1 != c && print[i + 1][j]) {
                len_cur = mx_strlen(print[i][j]);
                t = max_len / 8 + 1;
                t -=len_cur / 8;

                for(int u = 0; u < t; u++) {
                    mx_printchar('\t');
                }
            }
            else {
                mx_printchar('\n');
            }
            mx_strdel(&print[i][j]);
        }
    }
}

