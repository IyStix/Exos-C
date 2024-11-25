#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

size_t list_length(struct list *list)
{
    size_t length = 0;

    while (list)
    {
        length++;
        list = list->next;
    }
    return length;
}


void list_destroy(struct list *list)
{
    while(list)
    {
        struct list *next = list->next;
        free(list->data);
        free(list);
        list=next;
    }
}

struct list *list_prepend(struct list *list, const void *value, size_t data_size)
{
    struct list *new_list = malloc(sizeof(struct list));
    if (!new_list)
        return NULL;
    
    new_list->data = malloc(data_size);
    if (!new_list->data)
    {
        free(new_list);
        return NULL;
    }

    memcpy(new_list->data, value, data_size);

    new_list->next = list;
    return new_list;
}
