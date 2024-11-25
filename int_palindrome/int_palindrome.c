#include <stdio.h>

int int_palindrome(int n)
{
    if (n < 0)
    {
        return 0;
    }
    int d = 0;
    int a = n;
    while (a != 0)
    {
        d = d * 10;
        d = d + a % 10;
        a = a / 10;
    }
    if (n == d)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
