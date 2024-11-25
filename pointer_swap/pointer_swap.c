#include <stdio.h>

void pointer_swap(int **a, int **b)
{
    int *temp_ptr = NULL;
    temp_ptr = *a;
    *a = *b;
    *b = temp_ptr;
}
