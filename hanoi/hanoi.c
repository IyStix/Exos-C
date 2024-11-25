#include <stdio.h>

void hanoi_recursiv(unsigned d, char s, char dest, char temp)
{
    if (d > 0)
    {
        hanoi_recursiv(d - 1, s, temp, dest);
        putchar('0' + s);
        putchar('-');
        putchar('>');
        putchar('0' + dest);
        putchar('\n');
        hanoi_recursiv(d - 1, temp, dest, s);
    }
}

void hanoi(unsigned n)
{
    hanoi_recursiv(n, 1, 3, 2);
}
