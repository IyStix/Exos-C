#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *new_node = malloc(sizeof(struct list));
    if (!new_node)
        return;

    new_node->data = elt;
    new_node->next = NULL;

    if (fifo->tail)
        fifo->tail->next = new_node;
    else
        fifo->head = new_node;

    fifo->tail = new_node;
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (!fifo->head)
        return;

    struct list *temp = fifo->head;
    fifo->head = fifo->head->next;
    free(temp);

    if (!fifo->head)
        fifo->tail = NULL;

    fifo->size--;
}

void fifo_print(const struct fifo *fifo)
{
    struct list *current = fifo->head;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}
