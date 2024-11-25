#include <stdlib.h>

#include "fifo.h"

struct fifo *fifo_init(void)
{
    struct fifo *new_fifo = malloc(sizeof(struct fifo));
    if (!new_fifo)
        return NULL;

    new_fifo->head = NULL;
    new_fifo->tail = NULL;
    new_fifo->size = 0;

    return new_fifo;
}

void fifo_clear(struct fifo *fifo)
{
    while (fifo->head)
    {
        struct list *tmp = fifo->head;
        fifo->head = fifo->head->next;
        free(tmp);
    }
    fifo->tail = NULL;
    fifo->size = 0;
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}
