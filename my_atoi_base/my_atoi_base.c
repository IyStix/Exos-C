#include <stdio.h>

static int find_char_index(char c, const char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == c)
        {
            return i;
        }
    }
    return -1;
}

static int is_space(char c)
{
    return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
            || c == '\v');
}

int my_atoi_base(const char *str, const char *base)
{
    if (!str || !base || !*base || !*(base + 1))
        return 0;

    int base_length = 0;
    while (base[base_length])
    {
        if (base[base_length] == '+' || base[base_length] == '-'
            || is_space(base[base_length])
            || find_char_index(base[base_length], base + base_length + 1) != -1)
            return 0;
        base_length++;
    }

    while (is_space(*str))
        str++;

    int sign = 1;
    if (*str == '-' || *str == '+')
    {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }

    int result = 0;
    int digit;
    while (*str)
    {
        digit = find_char_index(*str, base);
        if (digit == -1)
            return 0;
        result = result * base_length + digit;
        str++;
    }

    return sign * result;
}
