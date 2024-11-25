#include "my_strcasecmp.h"

#include <stddef.h>

int my_strcasecmp(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        return 0;
    }
    while (*s1 && *s2)
    {
        char a1 = *s1;
        char a2 = *s2;
        if (a1 >= 'A' && a1 <= 'Z')
        {
            a1 += ('a' - 'A');
        }
        if (a2 >= 'A' && a2 <= 'Z')
        {
            a2 += ('a' - 'A');
        }
        if (a1 != a2)
        {
            return (a1 - a2);
        }
        s1++;
        s2++;
    }

    return (*s1 - *s2);
}
