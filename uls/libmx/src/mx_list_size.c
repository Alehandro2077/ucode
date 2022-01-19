#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int ct = 0;
    
    while (list)
    {
        list = list->next;
        ct++;
    }

    return ct;
}

