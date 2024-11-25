#include "my_strstr.h"

int my_strstr(const char *haystack, const char *needle)
{
    if (!*needle)
    {
        return 0;
    }
    for (int i = 0; haystack[i]; i++)
    {
        int j = 0;
        while (haystack[i + j] == needle[j])
        {
            if (needle[j + 1] == '\0')
            {
                return i;
            }
            j++;
        }
    }
    if (*needle == '\0')
    {
        return 0;
    }
    while (*haystack != '\0')
    {
        const char *h = haystack;
        const char *n = needle;
        while (*n != '\0' && *h == *n)
        {
            h++;
            n++;
        }
        if (*n == '\0')
        {
            return haystack - h;
        }
        haystack++;
    }
    return -1;
}
