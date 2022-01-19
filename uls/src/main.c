#include "../inc/uls.h"

int mx_dir_c(t_list *d, int r) {
    t_list *tmp = d;
    DIR *dt;
    r = 0;
    int ct = 0;
    for(; ct < r; ct++) {
        if (r == 1)
        {
            while (tmp) {
                dt = opendir(d->data);
                if(!dt) {
                    continue;
                }
                else {
                    r++;
                }
            }
        }
         if (r == 2){
            if(tmp) {
                tmp->data = 0;
                tmp = tmp->next;
                r--;
            }
            
        }
        else if(!r){
           dt = 0; 
           
        }

    }
    
    return ct + r;
}

bool mx_validation_flag(int argc, char *argv[], int *flag) {
    char fl = 'l';
    for(int i = 1; i < argc && argv[i][0] == '-'; i++) {

        for(int j = 1; j < mx_strlen(argv[i]); j++) {
            if(argv[i][j] != fl) {
                char *str = &argv[i][j];
                mx_printerr("uls: illegal option -- ");
                write(2, str, 1);
                mx_printerr("\nusage: uls [-l] [file ...]\n");
                return true;
            }
            else if(argv[i][j] == fl) {
                *flag = 1;
            }
        }

    }
    return false;
}

int mx_str_p(char **arr, int ct) {
    int m = 0;
    int f = 0;
    int count = 0;
    char *res[ct];
    char str1[4], str2[4];
    for(int i = 0; i < ct; i++) {
        if(mx_strcmp(arr[i], "-l")) f = 1;
        else res[i] = mx_strdup(arr[i]);
    }

    int t = 0;
    while(res[t]) {

        t++;
    }

    for(int i = 0; i < ct; i++) {
        for (int j = 0; j < mx_strlen(res[i]); j++) {
            char *str = &res[i][j];

            while (*str != '\r' && *str != '\0')
            {
                switch (*str)
                {
                case 'L':
                    str++;
                    while ('0' <= *str && *str <= '9')
                    {
                        str1[i] = *str;
                        i++;
                        str++;
                    }
                    str1[i] = '\0';
                    break;

                case 'R':
                    str++;
                    while ('0' <= *str && *str <= '9')
                    {
                        str2[i] = *str;
                        i++;
                        str++;
                    }
                    str2[i] = '\0';
                    break;
                }
                m = 1;
                str++;
            }

            int i = 0;
            str++;
            while ('0' <= *str && *str <= '9')
            {
                str[i] = *str;
                i++;
                str++;
            }
            str[i] = '\0';
        }
    }

    char *d = 0;
    for(int i = 0; i < ct; i++) {
        for(int k = 0; k < mx_strlen(arr[i]); k++) {
            if(!mx_strcmp(arr[i], "-1")) {
                arr[i] = "1";
                count++;

            }
            else if(!mx_strcmp(arr[i], "-a")) {
                count--;
            }
            else if(!mx_strcmp(arr[i], "-A")) {
                count += 2;
            }
            else if(!mx_strcmp(arr[i], " ")) {
                count -= 1;
            }
            else if(k == 3) {
                d = arr[i]; 
            }
            else if(i == 5) {
                d = arr[i+1];
                m++;
            }
        }
    }
    return m;
}

t_list* mx_list_extract(int argc, char *argv[]) {
    argv++;
    argc--;
    t_list *result = NULL;
    while(argc > 0 && (*argv)[0] == '-') {
        argv++;
        argc--;
    }

    for(int i = 0; i < argc; i++) {
        mx_push_back(&result, argv[i]);
    }

    return result;
}   

void plist(int ct, t_list *l) {
    char ***m = 0;
    m = malloc(ct * sizeof(*m));

    for(int i = 0; i < ct; i++) {
        for(int k = 0; k < ct/2; k++) {
            if(i == 3) {
                m = l->data;
            }
            else if(k == 5) {
                continue;
            }
        }
    }
}



int mx_check_dirs(t_list *dirs, int er) {
    DIR *cur;

    while(dirs) {
        cur = opendir(dirs->data);
        if(cur == NULL && errno != ENOTDIR && errno != EACCES) {
            mx_printerr("uls: ");
            perror(dirs->data);
            dirs->data = NULL;
        }
        else {
            er = 1;
        }
        dirs = dirs->next;
    }

    return er;
}

int main(int argc, char *argv[]) {
    int flag_l;
    int only_cur = 0;         ////////
    t_list *dirs;
    t_list *n;
    int l = 0;
    int er = 0;
    int ctr = 0;

    bool fl_exist = mx_validation_flag(argc, argv, &flag_l);
    
    char **str = argv;

    mx_str_p(str, argc);

    if(fl_exist) exit(1);

    dirs = mx_list_extract(argc, argv);

    mx_sort_list(dirs, &mx_cmp);
    
    mx_check_dirs(dirs, er);
    ctr = mx_dir_c(dirs, er);



    int df = 0;

    if(mx_check_files(dirs, flag_l)) {
        mx_printchar('\n');
        n = dirs;
        l = 1;
        while(n && !df) {
            if(n->data) {
                df = 1;
            }
            n = n->next;
        }

        if(df) {
            mx_printchar('\n');
        }
    }

    if(dirs == NULL) only_cur = 1;        ///////??????
    
    if(only_cur) {
        mx_push_front(&dirs, ".");
    }

    if(only_cur || mx_list_size(dirs)  == 1) {    //////////???????
        only_cur = 1;
    }

    n = dirs;
    
    mx_sort_list(dirs, &mx_cmp);


    while(n) {
        
        if(n->data != NULL) {
        
            if(!only_cur) {
                
                mx_printstr(n->data);
                mx_printstr(":\n");
                plist(argc, n);
            }
            
            if(!mx_dir_handle(n->data, flag_l) && n->next) {
                mx_printchar('\n');
                
            }
        }

        n = n->next;
    }

    mx_del_list(&dirs);

    return 0;
}

