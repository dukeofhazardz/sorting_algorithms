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
	size_t i, len = size;
	bool bubbly = false;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				/**
				 * temp = array[i];
				 * array[i] = array[i + 1];
				 * array[i + 1] = temp;
				 */
				swap(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
