#include <stdio.h>

unsigned int greatest_divisor(unsigned int n)
{
    unsigned int champ = n - 1;
    if (champ == 0 || champ == 1)
    {
        return n;
    }
    if (n % champ != 0)
    {
        while (n % champ != 0)
        {
            champ--;
        }
        return champ;
    }
    else
    {
        return n;
    }
}
