#include "sort.h"

/**
 *counting_sort - sort and array by counting sort method
 *@array: input array to be sorted
 *@size: size of the array
 *
 *Return: Nothing,
 */
void counting_sort(int *array, size_t size)
{
	size_t j;
	int max_value, i;
	int *count_array, *sort_array = malloc(size * sizeof(int));

	if (size < 2)
		return;
	max_value = array[0];
	if (sort_array == NULL)
	{
		free(sort_array);
		return;
	}
	for (j = 0; j < size; j++)
		sort_array[j] = array[j];
	for (j = 0; j < size; j++)
	{
		if (array[j] > max_value)
			max_value = array[j];
	}
	count_array = malloc((max_value + 1) * sizeof(int));
	if (count_array == NULL)
	{
		free(count_array);
			return;
	}
	for (i = 0; i <= max_value; i++)
		count_array[i] = 0;
	for (j = 0; j < size; j++)
		count_array[array[j]]++;
	for (i = 1; i <= max_value; i++)
		count_array[i] = count_array[i] + count_array[i - 1];
	print_array(count_array, max_value + 1);
	for (j = 0; j < size; j++)
	{
		sort_array[count_array[array[j]] - 1] = array[j];
		count_array[array[j]] = count_array[array[j]] - 1;
	}
	for (j = 0; j < size; j++)
		array[j] = sort_array[j];
	free(count_array), free(sort_array);
}
