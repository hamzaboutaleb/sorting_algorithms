#include "sort.h"

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
 * selection_sort - sort array of size
 * @array: array to sort
 * @size: siez of array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t max;

	for (i = 0; i < size; i++)
	{
		max = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[max])
				max = j;
		}
		swap(array + i, array + max);
		print_array(array, size);
	}
}
