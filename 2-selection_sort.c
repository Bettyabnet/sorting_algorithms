#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *		    using the selection sort algorithm.
 *
 * @array: array of integers.
 * @size: size of the array.
 *
 * Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
    int *min;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min = array + i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < *min)
                min = array + j;
        }

        if ((array + i) != min)
        {
            int tmp = array[i];
            array[i] = *min;
            *min = tmp;
            print_array(array, size);
        }
    }
}
