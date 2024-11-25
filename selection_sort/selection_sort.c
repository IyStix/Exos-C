#include <stddef.h>

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    unsigned mini = start;
    for (unsigned k = start; k < size; k++)
    {
        if (arr[k] < arr[mini])
        {
            mini = k;
        }
    }
    return mini;
}

void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
    return;
}

void selection_sort(int arr[], unsigned size)
{
    for (unsigned s = 0; s < size; s++)
    {
        unsigned mini = array_min(arr, s, size);
        unsigned index = s;
        if (arr[mini] < arr[index])
        {
            index = mini;
        }
        int swp = arr[s];
        arr[s] = arr[index];
        arr[index] = swp;
    }
}
