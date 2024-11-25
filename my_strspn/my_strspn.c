#include "my_strspn.h"

#include <stddef.h>

size_t my_strspn(const char *s, const char *accept)
{
    size_t counter = 0;
    while (*s)
    {
        int accepted = 0;
        const char *a = accept;
        while (*a)
        {
            if (*s == *a)
            {
                accepted = 1;
                break;
            }
            a++;
        }
        if (accepted)
        {
            counter++;
        }
        else
        {
            break;
        }
        s++;
    }
    return counter;
}
