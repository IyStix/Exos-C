#include <stdio.h>

void display_square(int width)
{
    if (width <= 0)
    {
        return;
    }
    else if (width % 2 == 0)
    {
        width = width + 1;
    }
    for (int i = 0; i < ((width + 1)) / 2; i++)
    {
        if (i == 0 || i == ((width + 1) / 2) - 1)
        {
            for (int k = 0; k < width; k++)
            {
                putchar('*');
            }
            putchar('\n');
        }
        else
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0 || j == width - 1)
                {
                    putchar('*');
                }
                else
                {
                    putchar(' ');
                }
            }
            putchar('\n');
        }
    }
}

int main(void)
{
    display_square(11);
}
