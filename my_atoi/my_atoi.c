#include "my_atoi.h"

#include <stdio.h>

int my_atoi(const char *str)
{
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;

    int sign = 1;
    if (*str == '+' || *str == '-')
    {
        sign = (*str == '+') ? 1 : -1;
        str++;
    }

    if (*str == ' ' || (*str >= 9 && *str <= 13))
        return 0;

    int r = 0;
    int digits = 0;

    while (*str != '\0')
    {
        if (*str < '0' || *str > '9')
            return 0;

        r = r * 10 + (*str - '0');
        digits = 1;
        str++;
    }

    if (!digits)
        return 0;

    return r * sign;
}
