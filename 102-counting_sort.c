#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a counting array with size max + 1 and initialize to 0 */
    int *counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    for (int i = 0; i <= max; i++)
        counting_array[i] = 0;

    /* Count the occurrences of each element in the array */
    for (size_t i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print the counting array */
    print_array(counting_array, max + 1);
    
    /* Modify the counting array to store the actual position of each element */
    for (int i = 1; i <= max; i++)
        counting_array[i] += counting_array[i - 1];

    /* Create a temporary array to store the sorted elements */
    int *temp_array = malloc(size * sizeof(int));
    if (temp_array == NULL)
    {
        free(counting_array);
        return;
    }

    /* Build the sorted array using the counting array */
    for (int i = size - 1; i >= 0; i--)
    {
        temp_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (size_t i = 0; i < size; i++)
        array[i] = temp_array[i];

    /* Free allocated memory */
    free(counting_array);
    free(temp_array);
}
