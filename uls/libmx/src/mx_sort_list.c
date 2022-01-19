#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *)) {
    if(cmp == NULL || list == NULL) return list;

    t_list *tmp = list;
    int ct = 0;

    while(tmp) {
        tmp = tmp->next;
        ct++;
    }

    for(int i = 0; i < ct; i++) {
        tmp = list;

        for(int j = 0; j < ct - 1; j++) {
            if(cmp(tmp->data, tmp->next->data)) {
                void *data = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = data;
            }
            tmp = tmp->next;
        }
    }

    return list;
}

