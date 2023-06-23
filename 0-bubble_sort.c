#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sorting array with bubble sort algorithm
 * @array: pointer to array to sort
 * @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, is_swap;

	for (i = 0; i < size; i++)
	{
		is_swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				is_swap = 1;
				print_array(array, size);
			}
		}
		if (is_swap == 0)
			return;
	}
}
