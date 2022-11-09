#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: unsort array
 * @size: array length
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	int pi = partition(array, size);

	if (array && pi > 0)
	{
		quick_sort(array, (pi - 1));
		quick_sort(array, (size - pi - 1));
	}
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
		if (array[j] < pivot)
		{
			i++;
			tmp = *(array + i);
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	tmp = *(array + (i + 1));
	array[i + 1] = array[size - 1];
	array[size - 1] = tmp;
	print_array(array, size);
	return (i + 1);
}
