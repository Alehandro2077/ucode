#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    if(!list) {
        return;
    }

    t_list *new_node = mx_create_node(data);

    if(!*list) {
        *list = new_node;
        return;
    }

    t_list *tmp = *list;

    while(tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = new_node;
}

