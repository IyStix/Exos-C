#include "my_c_tail.h"

#include <stdlib.h>

#define BUFFER_SIZE 9999

int read(int fd, void *buf, size_t count);
int write(int fd, const void *buf, size_t count);

struct line_context
{
    char **lines;
    size_t *line_count;
    unsigned int n;
};

static char *process_line(char *line_start, size_t line_len,
                          struct line_context *ctx)
{
    char *new_line = malloc(line_len + 2);
    if (!new_line)
        return NULL;

    for (size_t j = 0; j < line_len; j++)
        new_line[j] = line_start[j];
    new_line[line_len] = '\n';
    new_line[line_len + 1] = '\0';

    if (*(ctx->line_count) < ctx->n)
    {
        ctx->lines[*(ctx->line_count)] = new_line;
        (*(ctx->line_count))++;
    }
    else
    {
        free(ctx->lines[0]);
        for (size_t j = 1; j < ctx->n; j++)
            ctx->lines[j - 1] = ctx->lines[j];
        ctx->lines[ctx->n - 1] = new_line;
    }

    return new_line;
}

static void cleanup_and_exit(char **lines, size_t line_count)
{
    for (size_t i = 0; i < line_count; i++)
        free(lines[i]);
    free(lines);
}

void stdintail(unsigned int n)
{
    char buffer[BUFFER_SIZE];
    int bytes_read;
    char **lines = malloc(n * sizeof(char *));
    size_t line_count = 0;
    char *line_start = buffer;
    size_t line_len = 0;
    struct line_context ctx = { lines, &line_count, n };

    if (n == 0 || !lines)
        return;

    while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
    {
        for (int i = 0; i < bytes_read; i++)
        {
            if (buffer[i] == '\n')
            {
                if (!process_line(line_start, line_len, &ctx))
                {
                    cleanup_and_exit(lines, line_count);
                    return;
                }
                line_start = &buffer[i + 1];
                line_len = 0;
            }
            else
                line_len++;
        }
        line_start = buffer;
    }

    if (bytes_read == -1)
    {
        cleanup_and_exit(lines, line_count);
        return;
    }

    for (size_t i = 0; i < line_count; i++)
    {
        size_t len = 0;
        while (lines[i][len] != '\0')
            len++;
        write(1, lines[i], len);
        free(lines[i]);
    }
    free(lines);
}
