#include <stddef.h>
#include <stdio.h>

#define INT_VECTOR_LENGTH 100

struct int_vector
{
    size_t size;
    int data[INT_VECTOR_LENGTH];
};

void int_vector_print(const struct int_vector vec)
{
    if (vec.size > 0)
    {
        for (size_t i = 0; i < vec.size; i++)
        {
            printf("%d", vec.data[i]);
            if (i < vec.size - 1)
            {
                printf(" ");
            }
        }
    }
    printf("\n");
}
