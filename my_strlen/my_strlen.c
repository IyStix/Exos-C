#include "my_strlen.h"

#include <stdlib.h>

size_t my_strlen(const char *s)
{
    int i = 0;
    char l = s[0];
    size_t t = 0;
    while (l != '\0')
    {
        i++;
        t++;
        l = s[i];
    }
    return t;
}
