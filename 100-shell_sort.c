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
 * shell_sort - A function that sorts an array of integers in ascending
 *		order using the Shell sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
