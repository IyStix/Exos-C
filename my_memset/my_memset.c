#include "my_memset.h"

#include <stddef.h>

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *p = s;
    unsigned char value = c & 0xFF;
    for (size_t i = 0; i < n; i++)
    {
        p[i] = value;
    }

    return s;
}
