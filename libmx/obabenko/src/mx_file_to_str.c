#include "../inc/libmx.h" 

char *mx_file_to_str(const char *file) {
    if(!file) return NULL;

    int  f = open(file, O_RDONLY);
    if(f < 0) return NULL;

    char buf;
    int len = 0;

    while(read(f, &buf, 1)) {
        len++;
    }

    if(close(f) < 0) {
        return NULL;
    }

    if(len == 0) return NULL;

    f = open(file, O_RDONLY);

    if(f < 0) return NULL;

    char *a = mx_strnew(len);

    read(f, a, len);

    if(close(f) < 0) {
        return NULL;
    }

    return a;
}

