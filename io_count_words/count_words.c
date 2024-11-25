#include <stddef.h>
#include <stdio.h>

int count_words(const char *file_in)
{
    if (file_in == NULL)
        return -1;

    FILE *file = fopen(file_in, "r");
    if (file == NULL)
        return -1;

    int word_count = 0;
    int in_word = 0;
    int c;

    while ((c = fgetc(file)) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            word_count++;
        }
    }

    fclose(file);
    return word_count;
}
