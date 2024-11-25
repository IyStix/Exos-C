#include "my_itoa.h"

#include <stdio.h>

char *my_itoa(int value, char *s)
{
    if (!s)
        return 0;

    char *original_s = s;
    int is_negative = 0;
    unsigned int uvalue;

    if (value < 0)
    {
        is_negative = 1;
        uvalue = 0 - value;
    }
    else
    {
        uvalue = value;
    }

    do
    {
        *s++ = "0123456789"[uvalue % 10];
        uvalue /= 10;
    } while (uvalue > 0);

    if (is_negative)
        *s++ = '-';

    *s = '\0';

    char *start = original_s;
    char *end = s - 1;
    while (start < end)
    {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }

    return original_s;
}
