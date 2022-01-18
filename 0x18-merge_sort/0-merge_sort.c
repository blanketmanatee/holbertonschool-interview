#include "sort.h"

/**
 * merge - merge
 * @array: ptr
 * @size: size of array
 * @m: middle
 * @tmp: ptr
 */

void merge(int *array, int size, int m, int *tmp)
{
    int i, j, k;

    printf("Merging...\n[left]: ");
    print_array(array, m);
    printf("[right]: ");
    print_array(array + m, size - m);
    for (i = 0, j = m, k = 0; k < size; k++)
    {
        if (j == size)
        {
            tmp[k] = array[i];
            i++;
        }
        else if (i == m)
        {
            tmp[k] = array[j];
            j++;
        }
        else if (array[j] < array[i])
        {
            tmp[k] = array[j];
            j++;
        }
        else
        {
            tmp[k] = array[i];
            i++;
        }
    }
    for (i = 0; i < size; i++)
    {
        array[i] = tmp[i];
    }
    printf("[Done]: ");
    print_array(tmp, size);
}