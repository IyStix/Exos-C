#include <stddef.h>
#include <stdlib.h>
#include "../include/dlist.h"

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}
