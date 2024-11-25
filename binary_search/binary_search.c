#include <stddef.h>
#include <stdio.h>

int binary_search_recursive(const int vec[], int left, int right, int elt)
{
    if (left > right)
    {
        return -1;
    }

    int middle = (left + right) / 2;

    if (vec[middle] == elt)
    {
        return middle;
    }
    else if (vec[middle] < elt)
    {
        return binary_search_recursive(vec, middle + 1, right, elt);
    }
    else
    {
        return binary_search_recursive(vec, left, middle - 1, elt);
    }
}

int binary_search(const int vec[], int size, int elt)
{
    return binary_search_recursive(vec, 0, size - 1, elt);
}
