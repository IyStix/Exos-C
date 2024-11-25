#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *new_heap = malloc(sizeof(struct heap));
    if (new_heap == NULL)
        return NULL;

    new_heap->size = 0;
    new_heap->capacity = 8;
    new_heap->array = calloc(new_heap->capacity, sizeof(int));

    if (new_heap->array == NULL)
    {
        free(new_heap);
        return NULL;
    }

    return new_heap;
}
