#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: unsort array
 * @size: array length
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array && size >= 2)
		quick_sort_rec(array, 0, size - 1);
}

/**
 * partition - partitions the array
 * @array: ....
 * @size: .....
 * Return: integer
 */

int partition(int *array, size_t size)
{
	int pivot = array[size - 1];
	int i = -1;
	int tmp;
	size_t j;

	for (j = 0; j <= size - 2; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = *(array + i);
			array[i] = array[j];
			array[j] = tmp;
			if (tmp != array[i])
				print_array(array, size);
		}
	}
	tmp = *(array + (i + 1));
	array[i + 1] = array[size - 1];
	array[size - 1] = tmp;
	if (tmp != array[i + 1])
		print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_rec - ....
 * @lo: .....
 * @hi: .....
 * @array: ....
 * Return: ....
 */

void quick_sort_rec(int *array, int lo, int hi)
{
	int pi;

	if (lo < hi)
	{
		pi = partition(array, hi + 1);

		quick_sort_rec(array, lo, pi - 1);
		quick_sort_rec(array, pi + 1, hi);
	}
}
