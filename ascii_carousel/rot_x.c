#include <stddef.h>

void rot_x(char *s, int x)
{
    if (s == NULL)
    {
        return;
    }
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            char b = (s[i] >= 'A' && s[i] <= 'Z') ? 'A' : 'a';
            s[i] = b + (s[i] - b + x + 26) % 26;
        }
    }
}
