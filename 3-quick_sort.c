#include "sort.h"
/**
 * lomuto - Lomuto partition scheme for quicksort algorithm
 *
 * @a: Array to sort
 * @l: lowest index of array
 * @h: highest index of array
 *
 * Return: index of pivot
 */
int lomuto(int *a, int l, int h)
{
	int p, i, j, t;
	static int size, k;

	if (k == 0)
		size = h + 1, k++;
	p = a[h];
	i = l;
	for (j = l; j < h; j++)
	{
		if (a[j] <= p)
		{
			if (i != j)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				print_array(a, size);
			}
			i++;
		}
	}
	if (i != h)
	{
		t = a[i];
		a[i] = a[h];
		a[h] = t;
		print_array(a, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - Quicksort recursive function
 *
 * @a: array to sort
 * @l: lowest index
 * @h: highest index
 */
void quick_sort_recursive(int *a, int l, int h)
{
	int p;

	if (l < h)
	{
		p = lomuto(a, l, h);
		quick_sort_recursive(a, l, p - 1);
		quick_sort_recursive(a, p + 1, h);
	}
}

/**
 * quick_sort - sorts array using quicksort algorithm
 *
 * @array: Array to sort
 * @size: Size of array to sort
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}
