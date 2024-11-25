#include <stdio.h>

int main(void)
{
    for (int i = 'a'; i < 'z'; i++)
    {
        putchar(i);
        putchar(' ');
    }
    putchar('z');
    putchar('\n');
    return 0;
}
