#include <stddef.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const unsigned char *p1 = s1;
    const unsigned char *p2 = s2;
    for (size_t i = 0; i < num; i++)
    {
        if (p1[i] != p2[i])
        {
            if (p1[i] < p2[i])
            {
                return -1;
            }

            else
            {
                return 1;
            }
        }
    }
    return 0;
}
