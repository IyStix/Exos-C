#include <stdio.h>

int int_sqrt(int n)
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (i * i == n)
            {
                return i;
            }
            if (i * i > n)
            {
                return i - 1;
            }
        }
    }
    return 0;
}
