#include "insertion_sort.h"

#include <assert.h>
#include <stddef.h>

void insertion_sort(void **array, f_cmp comp)
{
    assert(array != NULL);
    assert(comp != NULL);

    if (array[0] == NULL || array[1] == NULL)
    {
        return;
    }

    for (size_t i = 1; array[i] != NULL; i++)
    {
        void *key = array[i];
        int j = i - 1;

        while (j >= 0 && comp(array[j], key) > 0)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}
