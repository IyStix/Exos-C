#include "my_strtok_r.h"

#include <stdio.h>
#include <string.h>

static inline int is_delim(char c, const char *delim)
{
    while (*delim)
    {
        if (c == *delim++)
            return 1;
    }
    return 0;
}

static char *find_next_token(char *str, const char *delim)
{
    if (!str)
        return NULL;

    while (*str && is_delim(*str, delim))
        str++;

    return *str ? str : NULL;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *token_start;
    char *token_end;

    token_start = str ? str : *saveptr;

    token_start = find_next_token(token_start, delim);

    if (!token_start)
    {
        *saveptr = NULL;
        return NULL;
    }

    token_end = token_start;
    while (*token_end && !is_delim(*token_end, delim))
        token_end++;

    if (*token_end)
    {
        *token_end = '\0';
        *saveptr = token_end + 1;
    }
    else
    {
        *saveptr = NULL;
    }

    return token_start;
}
