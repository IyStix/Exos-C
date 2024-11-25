#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
    {
        return 1;
    }
    else
    {
        size_t spaces = n - 1;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < spaces - i; j++)
            {
                putchar(' ');
            }
            for (size_t k = 0; k < ((i + 1) * 2) - 1; k++)
            {
                putchar('*');
            }
            putchar('\n');
        }
        for (size_t i = 0; i < n / 2; i++)
        {
            for (size_t x = 0; x < spaces; x++)
            {
                putchar(' ');
            }
            putchar('*');
            putchar('\n');
        }
        return 0;
    }
}
