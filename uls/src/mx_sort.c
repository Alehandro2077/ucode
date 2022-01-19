#include "../inc/uls.h"

bool mx_cmp(void *a, void *b) {
    if(!a || !b) return true;

    if(mx_strcmp(a, b) > 0) return true;
    else return false;
     /////////?????
}

