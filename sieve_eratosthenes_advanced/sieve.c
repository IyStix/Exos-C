#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n < 2)
        return;
    char *primes = calloc(n, sizeof(char));
    if (!primes)
        return;
    int count = 0;
    for (int  i = 2; i<n; i++)
    {
        count ++;
        for(int j = i * i; j < n; j += i)
        {
            primes[j] = 1;
        }
    }

    printf("Number of primes: %d\n", count);
    free(primes);
}
