#include "sort.h"
/**
 * quick_sort - called from main
 * @array: int array
 * @size: size_t
 */
void quick_sort(int *array, size_t size)
{
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
	int partition_index = start;
	int temp, i;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			array[i] = array[partition_index];
			array[partition_index] = temp;
			partition_index++;
			print_array(array, size);
		}
	}
	temp = array[partition_index];
	array[partition_index] = array[end];
	array[end] = temp;
	print_array(array, size);
	return (partition_index);
}
