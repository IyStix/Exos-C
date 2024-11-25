#include <stddef.h>

void reverse(const char **arr)
{
    if (arr == NULL)
    {
        return;
    }
    const char **debut = arr;
    const char **fin = arr;

    while (*fin != NULL)
    {
        fin++;
    }
    fin--;
    while (debut < fin)
    {
        const char *temp = *debut;
        *debut = *fin;
        *fin = temp;
        debut++;
        fin--;
    }
}

void reverse_matrix(const char ***matrix)
{
    if (matrix == NULL)
    {
        return;
    }
    const char ***array = matrix;
    while (*array != NULL)
    {
        reverse(*array);
        array++;
    }
    const char ***debut = matrix;
    const char ***fin = matrix;
    while (*fin != NULL)
    {
        fin++;
    }
    fin--;
    while (debut < fin)
    {
        const char **temp = *debut;
        *debut = *fin;
        *fin = temp;
        debut++;
        fin--;
    }
}
