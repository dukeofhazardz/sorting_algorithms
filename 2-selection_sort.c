#include "sort.h"

/**
 * swap - Swaps two elements
 * @v1: value to be swapped
 * @v2: value to be swapped
 */
void swap(int *v1, int *v2)
{
	int temp;

	temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

/**
 * selection_sort - A function that sorts an array of integers
 *	in ascending order using the Selection sort algorithm
 * @array: Array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_index;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_index])
				min_index = j;
		if (min_index != i)
		{
			swap(&array[min_index], &array[i]);
			print_array(array, size);
		}
	}
}
