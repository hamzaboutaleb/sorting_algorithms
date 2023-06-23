#include "sort.h"
#include <stdio.h>

/**
 * swap - swap to values
 * @a: first
 * @b: second
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

size_t partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot;
    size_t i, j;

    j = low;
    pivot = array[high];
    for (i = low; i < high; i++)
    {
        if (array[i] <= pivot)
        {
            swap(&array[i], array[j]);
            j++;
        }
    }
    swap(&array[j], &array[high]);
    print_array(array, size);
    return (j);
}

void quick_sort_rec(int *array, int low, int high, size_t size)
{
    int pivot_i;
    
    if (low >= high)
        return;

    pivot_i = partition(array, low, high, size);
    quick_sort_rec(array, low, pivot_i - 1, size);
    quick_sort_rec(array, pivot_i + 1, high, size);
}

/**
 * quick_sort - sort array of elemnt using quick sort
 * @array: array
 * @size: size
*/
void quick_sort(int *array, size_t size)
{
    quick_sort_rec(array, 0, size - 1, size);
}
