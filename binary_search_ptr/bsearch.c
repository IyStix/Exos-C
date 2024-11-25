#include "bsearch.h"

int *binary_search(int *begin, int *end, int elt)
{
    while (begin < end)
    {
        int *middle = begin + (end - begin) / 2;
        if (*middle == elt)
        {
            return middle;
        }
        else if (*middle < elt)
        {
            begin = middle + 1;
        }
        else
        {
            end = middle;
        }
    }
    return begin;
}
