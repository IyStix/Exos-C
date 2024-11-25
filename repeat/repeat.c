#include <stdio.h>

void repeat(char str[], int n)
{
    for (int i = 0; i < n; i++)
    {
        puts(str);
    }
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        return 1;
    }
    char *s = argv[1];
    char n = argv[2][0];
    int id = n - '0';
    if (id >= 0 && id <= 9)
    {
        repeat(s, id);
        return 0;
    }
    return 1;
}
