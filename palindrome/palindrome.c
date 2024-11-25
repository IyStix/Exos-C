#include <assert.h>
#include <stddef.h>
#include <stdio.h>

int alphanumeric(char c)
{
    int a = (c >= 'a' && c <= 'z');
    return a || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int palindrome(const char *s)
{
    if (s == NULL)
    {
        return 0;
    }
    const char *start = s;
    const char *end = s;
    while (*end)
    {
        end++;
    }
    end--;
    while (start < end)
    {
        while (!alphanumeric(*start) && start < end)
        {
            start++;
        }
        while (!alphanumeric(*end) && start < end)
        {
            end--;
        }
        if (start < end && *start != *end)
        {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}
