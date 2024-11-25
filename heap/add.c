#include <stdlib.h>

#include "heap.h"

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapify_up(struct heap *heap, size_t index)
{
    while (index > 0)
    {
        size_t parent = (index - 1) / 2;
        if (heap->array[index] <= heap->array[parent])
            break;
        swap(&heap->array[index], &heap->array[parent]);
        index = parent;
    }
}

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        heap->capacity *= 2;
        int *new_array = realloc(heap->array, heap->capacity * sizeof(int));
        if (new_array == NULL)
            return;
        heap->array = new_array;
    }

    heap->array[heap->size] = val;
    heapify_up(heap, heap->size);
    heap->size++;
}
