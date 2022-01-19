#include "../inc/uls.h"

char *mx_get_path(char *path) {
    char *result;
    char **names = mx_strsplit(path, '/');
    for(int i = 0; names[i]; i++) {
        if(!names[i+1]) {
            result = mx_strdup(names[i]);
        }
    }
    mx_del_strarr(&names);
    return result;
}


char *mx_handle_flag(char *data, int *ct_block) {
    mode_t mode;
    char *name = mx_get_path(data);
    char *res = NULL;
    char *tmp;

    struct stat file;

    lstat(data, &file);       ////////

    mode = file.st_mode;

    *ct_block += file.st_blocks;

    if(S_ISREG(mode)) {
        res = mx_strjoin(res, "-");           ///////////////////////
    } 
    else if(S_ISDIR(mode)) {
        res = mx_strjoin(res, "d");
    }
    else if(S_ISLNK(mode)) {
        res = mx_strjoin(res, "l");
    }

    tmp = mx_strnew(9);
    tmp[0] = S_IRUSR & mode ? 'r' : '-';
    tmp[1] = S_IWUSR & mode ? 'w' : '-';
    tmp[2] = S_IXUSR & mode ? 'x' : '-';
    tmp[3] = S_IRGRP & mode ? 'r' : '-';
    tmp[4] = S_IWGRP & mode ? 'w' : '-';
    tmp[5] = S_IXGRP & mode ? 'x' : '-';
    tmp[6] = S_IROTH & mode ? 'r' : '-';
    tmp[7] = S_IWOTH & mode ? 'w' : '-';
    tmp[8] = S_IXOTH & mode ? 'x' : '-';

    res = mx_strjoin(res, tmp);
    res = mx_strjoin(res, "  ");          ///

    mx_strdel(&tmp);  ////

    res = mx_strjoin(res, mx_itoa(file.st_nlink));      ////////////  

    res = mx_strjoin(res, " ");

    res = mx_strjoin(res, getpwuid(file.st_uid)->pw_name);

    res = mx_strjoin(res, "  ");

    if(getgrgid(file.st_gid) == NULL) {
 
        res = mx_strjoin(res, mx_itoa(file.st_gid));      /////////////////

    }
    else {
        res = mx_strjoin(res, getgrgid(file.st_gid)->gr_name);
    }

    res = mx_strjoin(res, "  ");

    res = mx_strjoin(res, mx_itoa(file.st_size));    ///////////////
    res = mx_strjoin(res, " ");


    char **split_str = mx_strsplit(ctime(&file.st_mtimespec.tv_sec), ' ');
    char **clock = mx_strsplit(split_str[3], ':');
    time_t time_now = time(NULL);

    char **time_tmp = mx_strsplit(ctime(&time_now), ' ');

    res = mx_strjoin(res, split_str[1]);

    int ct = 0;
    for(; split_str[2][ct]; ct++);

    if(ct == 1) {
        res = mx_strjoin(res, "  ");
    }
    else if(ct == 2) {
        res = mx_strjoin(res, " ");
    }
    res = mx_strjoin(res, split_str[2]);
    res = mx_strjoin(res, " ");

    if(mx_strcmp(time_tmp[4], split_str[4])) {
        for(int i = 0; split_str[4][i]; i++){
            if(split_str[4][i] == '\n'){
                split_str[4][i] = '\0';
                break;
            }
        }

        res = mx_strjoin(res, " ");
        res = mx_strjoin(res, split_str[4]);
    }
    else {
        res = mx_strjoin(res, clock[0]);
        res = mx_strjoin(res, ":");
        res = mx_strjoin(res, clock[1]);
    }


    mx_del_strarr(&split_str);
    mx_del_strarr(&clock);
    mx_del_strarr(&time_tmp);

    res = mx_strjoin(res, " ");
    
    res = mx_strjoin(res, name);

    mx_strdel(&name);

    return res;
}


