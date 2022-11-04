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
	size_t i, j;
	int tmp;

	if (array)
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
}

/**
 * _putchar - write 1 char to stdout
 * @c: the char to write
 * Return: nothing
 */
void _putchar(char c)
{
	write(1, &c, 1);
}
