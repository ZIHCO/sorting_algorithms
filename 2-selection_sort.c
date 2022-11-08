#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending order
 * @array: unsorted array
 * @size: array length
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int min;

	if (array)
	{
		for (i = 0; i < size; i++)
		{
			min = array[i];
			for (j = i + 1; j < size; j++)
			{
				if (array[j] <= min)
				{
					min = *(array + j);
					k = j;
				}
			}
			if (min != array[i])
			{
				array[k] = array[i];
				array[i] = min;
				print_array(array, size);
			}
		}
	}
}
