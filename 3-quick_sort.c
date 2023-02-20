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
 * lomuto_part - A funcion that takes last elements as pivot places the
 *		pivot element at its correct position in the sorted array,
 *		and places all smaller (smaller than pivot) to left of pivot
 *		and all greater elements to right of pivot.
 * @array: Array to be sorted
 * @size: size of the array
 * @left: left side of pivot
 * @right: right side of pivot
 * Return: Partition
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
	int *pivot, low, high;

	pivot = array + right;
	for (high = low = left; low < right; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}
	if (array[high] > *pivot)
	{
		swap(array + high, pivot);
		print_array(array, size);
	}
	return (high);
}

/**
 * lomuto_sort - Implementing the quicksort through recursion
 * @array: array to be sorted
 * @size: size of the array
 * @right: The starting index of the partition to order
 * @left: The ending index of the partition to order
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_part(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - A function that sorts an array of integers
 *		in ascending order using the Quick sort algorithm
 * @array: Array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
