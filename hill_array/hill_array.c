#include <stdio.h>

int top_of_the_hill(int tab[], size_t len)
{
    size_t index = 0;
    int r = 0;
    if (len == 0)
    {
        r = -1;
    }
    for (size_t i = 0; (i < len - 1) && (tab[i] <= tab[i + 1]);)
    {
        if (tab[i] == tab[i + 1])
        {
            i++;
        }
        else
        {
            i++;
            index = i;
        }
    }
    if (r == 0)
        r = index;
    while (index < len - 1)
    {
        if (tab[index + 1] > tab[index])
        {
            r = -1;
        }
        index++;
    }
    for (size_t t = 0; t < len; t++)
    {
        if (tab[t] < 0)
        {
            r = -1;
        }
    }
    return r;
}

int main(void)
{
    int t[] = { 1, 3, 4, 7, 9, 6, 4, 1 };
    printf("%d\n", top_of_the_hill(t, 8));
}
