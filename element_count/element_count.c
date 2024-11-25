#include <stdio.h>

size_t element_count(int *begin, int *end)
{
    size_t count = 0;
    while (begin != end)
    {
        begin++;
        count++;
    }
    return count;
}
