#include <stdio.h>

void plus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
    {
        return;
    }
    int r = *a + *b;
    *a = r;
}

void minus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
    {
        return;
    }
    int r = *a - *b;
    *a = r;
}

void mult_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
    {
        return;
    }
    int r = *a * *b;
    *a = r;
}

int div_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
    {
        return 0;
    }
    int d = *a / *b;
    int r = *a % *b;
    *a = d;
    return r;
}
