#include <stdio.h>

double pi_generator(int precision)
{
    double pi = 1;
    if (precision <= 0)
    {
        return 2;
    }
    for (double i = precision; i > 0; i--)
    {
        double t  = i / (i * 2 + 1);
        pi = 1 + t * pi;
    }
    double two = 2;
    pi = two * pi;
    return pi;
}
