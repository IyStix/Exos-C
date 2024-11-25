#include <stdio.h>

#include "heap.h"

static void print_recursive(const struct heap *heap, size_t index,
                            size_t *count)
{
    if (index >= heap->size)
        return;

    if (*count > 0)
        printf(" ");
    printf("%d", heap->array[index]);
    (*count)++;

    print_recursive(heap, 2 * index + 1, count);
    print_recursive(heap, 2 * index + 2, count);
}

void print_heap(const struct heap *heap)
{
    size_t count = 0;
    print_recursive(heap, 0, &count);
    printf("\n");
}
