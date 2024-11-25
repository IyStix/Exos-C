#include <stddef.h>
#include <stdlib.h>
#include "../include/dlist.h"

int dlist_push_front(struct dlist *list, int element)
{
    struct dlist_item *item = malloc(sizeof(struct dlist_item));
    item->data = element;
    item->next = list->head;
    item->prev = NULL;

    if (list->head)
        list->head->prev = item;
    else
        list->tail = item;
    
    list->head = item;
    list->size++;
    return 1
}
