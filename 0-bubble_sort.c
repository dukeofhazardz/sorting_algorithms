#include "sort.h"

/**
 * swap - swap two variables
 * @v1: variable to be swapped
 * @v2: variable to be swapped
 *
 */
void swap(int *v1, int *v2)
{
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

/**
 * bubble_sort - A function that sorts an array of integers
 *	in ascending order using the Bubble sort algorithm
 * @array: Array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/**
				 * temp = array[j];
				 * array[j] = array[j + 1];
				 * array[j + 1] = temp;
				 */
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(array, size);
			}
		}
		if (swapped == false)
			break;
	}
}
