#include <stddef.h>
#include <stdlib.h>
#include "../include/dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *list = malloc(sizeof(struct dlist));
    if (!list)
        return NULL;
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}
