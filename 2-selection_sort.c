#include "sort.h"
/**
 *selection_sort - Sorts an array of integers in ascending order
 *@array: Array to be sorted
 *@size: size of array.
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t minIndex;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;

		/* Find index of minimum element in unsorted portion*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
		}

		/* Swap minimum element with first element of unsorted portion*/
		if (minIndex != i)
		{
			temp = array[i];

			array[i] = array[minIndex];
			array[minIndex] = temp;

			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
