#include "fifo.h"
#include <stddef.h>
#include <stdlib.h>

struct fifo *fifo_init(void)
{
    struct fifo *fifo = malloc(sizeof(struct fifo));
    if(!fifo)
        return NULL;
    
    fifo->head = NULL;
    fifo->tail = NULL;
    fifo->size = 0;
    return fifo;
}

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    
}
