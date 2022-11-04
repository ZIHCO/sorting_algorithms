#include "sort.h"

/**
 * bubble_sort -  sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: argument
 * @size: array size
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int tmp;

	if (array && size > 2)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 1; j < (size - i); j++)
			{
				if (array[j - 1] > array[j])
				{
					tmp = *(array + j);
					array[j] = array[j - 1];
					array[j - 1] = tmp;
				}
				print_array(array, size);
			}
		}
	}
	else if (array && size == 2)
	{
		if (array[i] > array[i + 1])
		{
			tmp = *array;
			array[i] = array[i + 1];
			array[i + 1] = tmp;
		}
		print_array(array, size);
	}
	else if (array)
		print_array(array, size);
}
