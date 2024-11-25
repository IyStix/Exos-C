#define _POSIX_C_SOURCE 200809L

#include <stdio.h>

int merge_files(const char *file_1, const char *file_2)
{
    FILE *f1 = fopen(file_1, "a");
    if (f1 == NULL)
        return -1;

    FILE *f2 = fopen(file_2, "r");
    if (f2 == NULL)
    {
        fclose(f1);
        return -1;
    }

    int c;
    while ((c = fgetc(f2)) != EOF)
    {
        if (fputc(c, f1) == EOF)
        {
            fclose(f1);
            fclose(f2);
            return -1;
        }
    }

    fclose(f1);
    fclose(f2);
    return 0;
}
