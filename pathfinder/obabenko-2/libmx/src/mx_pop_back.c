#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if(!head || !*head) {
        return;
    }

    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    t_list *tmp = *head;

    while(tmp && tmp->next->next) {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
}

