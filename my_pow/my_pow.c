#include <stdio.h>

int my_pow(int a, int b)
{
    int x = 0;
    if (b % 2 == 0)
    {
        int i = 1;
        while (x < b / 2)
        {
            i = a * a * i;
            x++;
        }
        return i;
    }
    else
    {
        int i = 1;
        while (x < b / 2)
        {
            i = a * a * i;
            x++;
        }
        i = i * a;
        return i;
    }
}
