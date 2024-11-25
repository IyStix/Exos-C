#include <stddef.h>

int verif(const char *str, char c)
{
    if (str == NULL)
    {
        return 0;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
        {
            return 1;
        }
    }

    return 0;
}

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet == NULL || alphabet[0] == '\0')
    {
        return 1;
    }

    for (int i = 0; alphabet[i] != '\0'; i++)
    {
        if (!verif(str, alphabet[i]))
        {
            return 0;
        }
    }

    return 1;
}
