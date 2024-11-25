#include "simple_fnmatch.h"

#include <stddef.h>

static int match(const char *pattern, const char *string)
{
    while (*pattern != '\0')
    {
        if (*pattern == '?')
        {
            if (*string == '\0')
                return 0;
            pattern++;
            string++;
        }
        else if (*pattern == '*')
        {
            pattern++;
            if (*pattern == '\0')
                return 1;
            while (*string != '\0')
            {
                if (match(pattern, string))
                    return 1;
                string++;
            }
            return 0;
        }
        else if (*pattern == '\\')
        {
            pattern++;
            if (*pattern == '\0' || *pattern != *string)
                return 0;
            pattern++;
            string++;
        }
        else
        {
            if (*pattern != *string)
                return 0;
            pattern++;
            string++;
        }
    }

    return *string == '\0';
}

int simple_fnmatch(const char *pattern, const char *string)
{
    if (pattern == NULL || string == NULL)
        return FNM_NOMATCH;

    return match(pattern, string) ? 0 : FNM_NOMATCH;
}
