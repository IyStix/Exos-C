#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    FILE *in = fopen(file_in, "r");
    if (!in)
    {
        return -1;
    }

    FILE *out = fopen(file_out, "w");
    if (!out)
    {
        fclose(in);
        return -1;
    }

    if (!content || !file_in || !file_out)
    {
        return -1;
    }

    size_t size = 100;
    char *line = NULL;
    int len = 0;

    while (len < n && getline(&line, &size, in) != -1)
    {
        len++;
        fputs(line, out);
    }
    getline(&line, &size, in);
    if (len < n)
    {
        fputs(line, out);
        fclose(in);
        fclose(out);
        free(line);
        return 1;
    }
    fputs(content, out);

    while (getline(&line, &size, in) != -1)
    {
        fputs(line, out);
    }
    free(line);
    fclose(in);
    fclose(out);

    return 0;
}
