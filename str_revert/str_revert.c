#include <stdio.h>

void str_revert(char str[])
{
    int count = 0;
    char *a;
    char *b;
    while (str[count] != 0)
    {
        count++;
    }
    a = str;
    b = str + count - 1;
    for (a = str; a < b;)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
        ++a;
        --b;
    }
    return;
}
