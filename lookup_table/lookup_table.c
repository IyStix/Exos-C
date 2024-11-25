#include <stddef.h>

void swap(unsigned char *a, unsigned char *b)
{
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(unsigned char arr[4])
{
    for (int i = 0; i < 2; i++)
    {
        swap(&arr[i], &arr[3 - i]);
    }
}

void apply_lut(unsigned char mat[4][4], const unsigned char lut[256])
{
    for (int i = 0; i < 4; i++)
    {
        reverse(mat[i]);
        for (int j = 0; j < 4; j++)
        {
            unsigned char x = mat[i][j];
            if (x < 255)
            {
                mat[i][j] = lut[x];
            }
            else
            {
                mat[i][j] = 0;
            }
        }
    }
}
