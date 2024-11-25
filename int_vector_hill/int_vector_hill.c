#include <assert.h>
#include <stddef.h>

#define INT_VECTOR_LENGTH 100

struct int_vector
{
    size_t size;
    int data[INT_VECTOR_LENGTH];
};

int int_vector_hill(struct int_vector vec)
{
    if (vec.size < 3)
    {
        return -1;
    }
    int top = -1;
    int max = vec.data[0];
    for (size_t i = 1; i < vec.size; i++)
    {
        if (vec.data[i] < 0)
        {
            return -1;
        }
        if (vec.data[i] == vec.data[i - 1])
        {
            return -1;
        }
        if (vec.data[i] > max)
        {
            max = vec.data[i];
        }
        else
        {
            if (top == -1)
            {
                return -1;
            }
            else
            {
                int vhill = 1;
                for (size_t j = i + 1; j < vec.size; j++)
                {
                    if (vec.data[j] >= vec.data[i])
                    {
                        vhill = 0;
                        break;
                    }
                }
                if (vhill)
                {
                    return top;
                }
            }
        }
        if (top == -1 && vec.data[i] > vec.data[i - 1])
        {
            top = i - 1;
        }
    }
    return -1;
}
