#include "functional_programming.h"

int foldl(int *array, size_t len, int (*func)(int, int))
{
    int acc = 0;
    for (size_t i = 0; i < len; i++)
    {
        acc = func(acc, array[i]);
    }
    return acc;
}
