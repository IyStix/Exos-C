#include "my_strlowcase.h"

#include <stddef.h>

void my_strlowcase(char *str)
{
    if (str == NULL)
    {
        return;
    }
    while (*str)
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str += ('a' - 'A');
        }
        str++;
    }
}
