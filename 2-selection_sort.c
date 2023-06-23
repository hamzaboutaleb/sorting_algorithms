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
	size_t min;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i != min)
		{
			swap(array + i, array + min);
			print_array(array, size);
		}
	}
}
