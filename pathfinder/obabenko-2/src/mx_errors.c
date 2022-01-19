#include "../inc/pathfinder.h"

void mx_first_line(char **str) {
    for(int i = 0; i < mx_strlen(str[0]); i++) {
        if(!mx_isdigit(str[0][i])) {
            char *error = "error: line 1 is not valid\n";
            mx_printerr(error);
            exit(1);
        }
    }
}


void mx_print_error_line(int count) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(count + 1));
    mx_printerr(" is not valid\n");
    exit(1);
}


int mx_line_loop(int count, char **str) {
    int f = 0;


    for(int i = 0; i << mx_strlen(str[count]); i++) {
        if (mx_isalpha(str[count][i]) && (f == 0 || f == 1)) continue;
        if (str[count][i] == '-' && f == 0 && i != 0) {
            f += 1;
            continue;
        }

        if (str[count][i] == ',' && f == 1 && mx_isdigit(str[count][i+1])
            && (mx_get_char_index(str[count], ',') -
            mx_get_char_index(str[count], '-') > 1)) {
            f *= -2;
            continue;
        }

        if (mx_isdigit(str[count][i]) && f == -2) continue;
        else {
            mx_del_strarr(&str);
            mx_print_error_line(count);
        }
    }

    return count + 1;
}


void mx_line(char **str, char *file) {
    int ct = 1;
    int i = 0;
    int line = 1;

    while(file[i]) {
        if(!mx_isdigit(file[0])) {
            mx_del_strarr(&str);
            mx_print_error_line(0);
        }
        if(file[i] == '\n' && mx_isalpha(file[i+1])) line++;

        if((file[i] == '\n' && !mx_isalpha(file[i+1]) && file[i+1] != '\0')
        ||(mx_isdigit(file[i]) && file[i+1] == '\0')) {
            mx_del_strarr(&str);
            mx_print_error_line(line);

        }
        i++;
    }
    while(str[ct]) {
        ct = mx_line_loop(ct, str);
    }
}


void mx_errors(int argc, char **argv) {
    if(argc != 2) {
        char *error = "usage: ./pathfinder [filename]\n";
        write(2, error, mx_strlen(error));
        exit(1);
    }

    const char *file = argv[1];

    mx_file_errors(file);
    char *tmp = mx_file_to_str(file);
    if(mx_get_char_index(tmp, '\n') == -1 || (mx_get_char_index(tmp, '\n') == 0 
    && mx_get_char_index(tmp, '-') == -1)) {
        free(tmp);
        exit(1);
    }

    char **str = mx_strsplit(tmp, '\n');

    if(str != NULL) {
        mx_first_line(str);
        mx_line(str, tmp);
        mx_del_strarr(&str);
    }

    free(tmp);
}

