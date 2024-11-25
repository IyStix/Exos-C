#include <stddef.h>

#define INT_VECTOR_LENGTH 100

struct int_vector
{
    size_t size;
    int data[INT_VECTOR_LENGTH];
};

int int_vector_max(const struct int_vector vec)
{
    if (vec.size == 0)
    {
        return 0;
    }
    int max_value = vec.data[0];
    for (size_t i = 1; i < vec.size; i++)
    {
        if (vec.data[i] > max_value)
        {
            max_value = vec.data[i];
        }
    }
    return max_value;
}
