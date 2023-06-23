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

/**
 * partition - partition function useing lomuto's algo
 * @array: pointer to arrau
 * @low: low index
 * @high: high index
 * @size: siez of array
 * Return: index of pivot
*/
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot;
	size_t i, j;

	j = low - 1;
	pivot = array[high];
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			j++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[j + 1] != array[high])
	{
		swap(&array[j + 1], &array[high]);
		print_array(array, size);
	}
	return (j + 1);
}

/**
 * quick_sort_rec - sort array of elemnt using quick sort
 * @array: array
 * @low: low indx
 * @high: high indx
 * @size: size
*/
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot_i;

	if (low > high)
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
