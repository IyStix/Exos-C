#include "int_vector_bubble_sort.h"

static struct int_vector int_vector_swap(struct int_vector vec, size_t i, size_t j)
{
    int tmp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = tmp;
    return vec;
}

struct int_vector int_vector_bubble_sort(struct int_vector vec)
{
    size_t i, j;
    for (i = 0; i < vec.size; i++)
    {
        for (j = 0; j < vec.size - i - 1; j++)
        {
            if (vec.data[j] > vec.data[j + 1])
            {
                vec = int_vector_swap(vec, j, j + 1);
            }
        }
    }
    return vec;
    
}
