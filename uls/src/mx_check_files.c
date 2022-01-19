#include "../inc/uls.h"

int mx_check_files(t_list *dirs, int flag_l) {
    DIR *cur;
    char *str;
    int ct_block = 0;
    int m = 0;

    while(dirs) {

        if(dirs->data == NULL) {
            dirs = dirs->next;
            continue;
        }

        cur = opendir(dirs->data);

        if(cur == NULL && errno == ENOTDIR) {
            m = 1;
            errno = 0;

            if(flag_l) {
                str = mx_handle_flag(dirs->data, &ct_block);
                mx_printstr(str);
                mx_printchar('\n');
                mx_strdel(&str);
            }
            else {
                mx_printstr(dirs->data);
                if(dirs->next && isatty(STDOUT_FILENO)) {
                    mx_printchar('\t');
                }
                else if(!isatty(STDOUT_FILENO)) {
                    mx_printchar('\n');
                }
            }
            dirs->data = NULL;
        }
        dirs = dirs->next;
    }

    return m;
}

