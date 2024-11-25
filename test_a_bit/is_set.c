#include <stdio.h>

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned int mask = 1 << (n - 1);
    if ((value & mask) != 0)
    {
        return 1;
    }
    else
        return 0;
}
