#include "sort.h"
/**
 * shell_sort - uses the Knuth sequence to sort an array
 *@array: Array to be Sorted
 *@size:size of the array
 *Return:Sorted Array (void)
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	size_t interval = 1;

	if (!array || !size || size < 2)
		return;

	while (interval < size / 3)
	{
		interval = interval * 3 + 1; /*Knuth sequence: n+1 = n * 3 + 1*/
	}

	while (interval > 0)
	{
		for (i = interval; i < size; ++i)
		{
			temp = array[i];
			j = i;

			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}
		/*Print array after each interval decrease*/
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
