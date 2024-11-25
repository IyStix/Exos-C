#include <assert.h>
#include <stddef.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int select_pivot(int *tab)
{
    return tab[0];
}

int partition(int *tab, int len)
{
    int pivot = select_pivot(tab);
    int i = 1;
    int j = len - 1;
    while (1)
    {
        while (i < len && tab[i] <= pivot)
        {
            i++;
        }
        while (j >= 0 && tab[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&tab[i], &tab[j]);
        }
        else
        {
            break;
        }
    }
    swap(&tab[0], &tab[j]);
    return j;
}

void quicksort_recursive(int *tab, int len)
{
    if (len <= 1)
    {
        return;
    }
    int pivot_index = partition(tab, len);
    quicksort_recursive(tab, pivot_index);
    quicksort_recursive(tab + pivot_index + 1, len - pivot_index - 1);
}

void quicksort(int *tab, int len)
{
    if (tab == NULL || len <= 1)
    {
        return;
    }
    quicksort_recursive(tab, len);
}
