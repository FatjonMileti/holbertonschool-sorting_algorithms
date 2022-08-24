#include "sort.h"
/**
 * quick_sort - called from main
 * @array: int array
 * @size: size_t
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_func(array, 0, size - 1, size);
}
/**
 * recursive_func - called from quick_sort
 * @array: int array
 * @start: starting index
 * @end: ending index
 * @size: size_t
 */
void recursive_func(int *array, int start, int end, size_t size)
{
	int partition_index;

	if (start >= end)
		return;
	partition_index = partition(array, start, end, size);
	recursive_func(array, start, partition_index - 1, size);
	recursive_func(array, partition_index + 1, end, size);
}
/**
 * partition - called from recursive_func
 * @array: int array
 * @start: starting index
 * @end: ending index
 * @size: size_t
 * Return: partition index
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start - 1, j, temp;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	i++;
	if (array[end] < array[i - 1])
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i);
}
