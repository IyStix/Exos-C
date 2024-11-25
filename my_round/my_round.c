#include <stdio.h>

int my_round(float n)
{
    int in = n;
    if (n > 0)
    {
        float r = n - in;
        if (r < 0.5)
        {
            return in;
        }
        else
        {
            return in + 1;
        }
    }
    if (n < 0)
    {
        float r = n - in;
        if ((-1 * r) < 0.5)
        {
            return in;
        }
        else
        {
            return in - 1;
        }
    }
    return 0;
}
