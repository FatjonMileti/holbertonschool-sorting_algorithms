#include "sort.h"
/**
 *
 */

void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
                return;

	temp = malloc(sizeof( *temp) * size);
	if (temp == NULL)
		return;


	sort(array,temp, size);
	free(temp);
}
/**
 *
 */
 
void sort(int *array, int *temp, size_t size)
{
	size_t i, j, k, mid;

	mid = size / 2;
	i = 0;
       	j = 0;

	if (size < 2)
		return;
	sort(array, temp, mid);
	sort(array + mid, temp + mid, size - mid);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);

	for(k = 0; k < size; k++)
	{
		if (j >= size - mid || (i < mid && array[i] < (array + mid)[j]))
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = (array + mid)[j];
			j++;
		}
	}
	for(k = 0; k < size; k++)
	{
		array[k] = temp[k];
	}
	
	printf("[Done]: ");
	print_array(array, size);
}
