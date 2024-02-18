#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    /* Initialize the gap using Knuth sequence */
    for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
        ;

    for (; gap > 0; gap /= 3)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                /* Shift elements until the correct position is found */
                array[j] = array[j - gap];
            }

            /* Place the current element in its correct position */
            array[j] = temp;

            /* Print the array after each decrease in interval (gap) */
            print_array(array, size);
        }
    }
}

