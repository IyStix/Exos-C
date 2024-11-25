#include <stdio.h>
#include <stdlib.h>

void *my_calloc(size_t n, size_t size)
{
    if (n == 0 || size == 0)
    {
        return NULL;
    }
    void *ptr = malloc(n * size);
    if (ptr != NULL)
    {
        unsigned char *ptrr = ptr;
        unsigned char *b = ptrr;
        for (size_t i = 0; i < n * size; i++)
        {
            b[i] = 0;
        }
    }
    return ptr;
}
