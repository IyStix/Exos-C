#include "functional_programming.h"

static int foldr_recursive(int *array, size_t len, int (*func)(int, int),
                           int acc)
{
    if (len == 0)
        return acc;
    return func(array[0], foldr_recursive(array + 1, len - 1, func, acc));
}

int foldr(int *array, size_t len, int (*func)(int, int))
{
    return foldr_recursive(array, len, func, 0);
}
