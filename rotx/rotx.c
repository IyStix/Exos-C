
int read(int fd, void *buf, unsigned int count);
int write(int fd, const void *buf, unsigned int count);

char rotate(char c, int x)
{
    if (c >= 'A' && c <= 'Z')
        return 'A' + ((c - 'A' + x % 26 + 26) % 26);
    if (c >= 'a' && c <= 'z')
        return 'a' + ((c - 'a' + x % 26 + 26) % 26);
    if (c >= '0' && c <= '9')
        return '0' + ((c - '0' + x % 10 + 10) % 10);
    return c;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 0;

    int x = 0;
    int sign = 1;
    int i = 0;

    if (argv[1][0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for (; argv[1][i]; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
            return 1;
        x = x * 10 + (argv[1][i] - '0');
    }

    x *= sign;

    char buf[4096];
    int n;

    while ((n = read(0, buf, sizeof(buf))) > 0)
    {
        for (int i = 0; i < n; i++)
            buf[i] = rotate(buf[i], x);

        if (write(1, buf, n) != n)
            return 1;
    }

    return n < 0 ? 1 : 0;
}
