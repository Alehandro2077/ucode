#include "../inc/uls.h"

void mx_print_list_l(char *name, t_list *list) {
    char *path;
    t_list *tmp = NULL;
    t_list *first = list;
    int ct_block = 0;

    while(list) {
        path = mx_strjoin(name, "/");
        path = mx_strjoin(path, list->data);
        mx_push_back(&tmp, mx_handle_flag(path, &ct_block));

        mx_strdel((char**)&list->data);
        mx_strdel(&path);

        list = list->next;
    }

    if(first) {
        mx_printstr("total ");
        mx_printint(ct_block);
        mx_printchar('\n');
        mx_col_print_l(tmp);
        mx_del_list(&tmp);
    }
}

bool mx_dir_handle(char *name, int flag_l) {
   
    char *namepath;
    int list_empty = 0;

    t_list *print_list = NULL;

    struct dirent *curf;
    DIR *dir;

    errno = 0;

    dir = opendir(name);

    if(errno != 0) {
        namepath = mx_get_path(name);
        mx_printerr("uls: ");
        perror(namepath);
        mx_strdel(&namepath);

        return 0;                     ///////////////////
    }         

    curf = readdir(dir);

    while(curf) {                                          /////////////////???????????
        if(curf->d_name[0] ==  '.') {
            curf = readdir(dir);
            continue;
        }
        mx_push_back(&print_list, mx_strdup(curf->d_name));
        curf = readdir(dir);
    }

    mx_sort_list(print_list, &mx_cmp);

    if(flag_l) {
        mx_print_list_l(name, print_list);
    }
    else {
        mx_print_list(print_list);
    }

    if(print_list) list_empty = 0;
    else if(!print_list) list_empty = 1;

    closedir(dir);

    mx_del_list(&print_list);

    return list_empty;
}

