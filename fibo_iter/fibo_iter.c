#include <stdio.h>

unsigned long fibo_iter(unsigned long n)
{
    if (n < 2)
    {
        return n;
    }
    unsigned long a = 0;
    unsigned long b = 1;
    for (unsigned long i = 0; i < n; i++)
    {
        unsigned long calc = a + b;
        b = a;
        a = calc;
    }
    return a;
}
