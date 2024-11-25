#include <assert.h>
#include <stdlib.h>

#include "heap.h"

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapify_down(struct heap *heap, size_t index)
{
    size_t largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != index)
    {
        swap(&heap->array[index], &heap->array[largest]);
        heapify_down(heap, largest);
    }
}

int pop(struct heap *heap)
{
    assert(heap->size > 0);

    int root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    heapify_down(heap, 0);

    if (heap->size < heap->capacity / 2 && heap->capacity > 8)
    {
        heap->capacity /= 2;
        int *new_array = realloc(heap->array, heap->capacity * sizeof(int));
        if (new_array != NULL)
            heap->array = new_array;
    }

    return root;
}
