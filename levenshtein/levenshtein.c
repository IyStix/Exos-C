#include "levenshtein.h"

#include <stddef.h>
#include <stdlib.h>

static size_t string_length(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

static size_t min3(size_t a, size_t b, size_t c)
{
    size_t m = a;
    if (b < m)
        m = b;
    if (c < m)
        m = c;
    return m;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t len1 = string_length(s1);
    size_t len2 = string_length(s2);

    size_t *matrix = malloc((len1 + 1) * (len2 + 1) * sizeof(size_t));
    if (!matrix)
        return 0;

    for (size_t i = 0; i <= len1; i++)
        matrix[i * (len2 + 1)] = i;

    for (size_t j = 0; j <= len2; j++)
        matrix[j] = j;

    for (size_t i = 1; i <= len1; i++)
    {
        for (size_t j = 1; j <= len2; j++)
        {
            size_t cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;

            matrix[i * (len2 + 1) + j] =
                min3(matrix[(i - 1) * (len2 + 1) + j] + 1,
                     matrix[i * (len2 + 1) + (j - 1)] + 1,
                     matrix[(i - 1) * (len2 + 1) + (j - 1)] + cost);
        }
    }

    size_t result = matrix[len1 * (len2 + 1) + len2];
    free(matrix);
    return result;
}
