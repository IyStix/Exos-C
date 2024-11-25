#include <stddef.h>

#define INT_VECTOR_LENGTH 100

struct int_vector
{
    size_t size;
    int data[INT_VECTOR_LENGTH];
};

int int_vector_vice_max(const struct int_vector vec)
{
    if (vec.size <= 2)
    {
        return -1;
    }

    int max = vec.data[0];
    int viceMax = vec.data[1];

    if (viceMax > max)
    {
        int temp = max;
        max = viceMax;
        viceMax = temp;
    }

    for (size_t i = 2; i < vec.size; i++)
    {
        if (vec.data[i] > max)
        {
            viceMax = max;
            max = vec.data[i];
        }
        else if (vec.data[i] > viceMax && vec.data[i] != max)
        {
            viceMax = vec.data[i];
        }
    }

    return viceMax;
}
