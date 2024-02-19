#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int max;
	int *count;
	int index;
		
    if (array == NULL || size < 2)
        return;


    max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (int i = 0; i <= max; i++)
        count[i] = 0;


    for (size_t i = 0; i < size; i++)
        count[array[i]]++;

    index = 0;
    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            array[index++] = i;
            count[i]--;
        }
    }

    print_array(count, max + 1);


    free(count);
}

