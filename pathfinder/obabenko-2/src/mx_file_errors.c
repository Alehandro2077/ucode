#include "../inc/pathfinder.h"

void mx_file_errors(const char *file) {
    int f_open = open(file, 'r');
    int buf_sz = 64;
    int size = 0;
    char buf[buf_sz];

    if(f_open < 0) {
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" does not exist\n");
        exit(1);
    }

    if((size = read(f_open, &buf, buf_sz)) == 0) {
        close(f_open);
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" is empty\n");
        exit(1);
    }
    close(f_open);
}

