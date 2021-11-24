#include "sort.h"

/**
 * swap - helper function to swap elements
 * @x: ptr
 * @y: ptr
 */

void swap(int *x, int *y)
{
int tmp = *x;
*x = *y;
*y = tmp;
}

/**
 * heap - build the heap
 * @arr: array
 * @x: heap size
 * @y: index
 * @size: number of items in array
 */

void heap(int *arr, int x, int y, size_t size)
{
int max = y;
int left = y * 2 + 1;
int right = y * 2 + 2;

if (left < x && arr[left] > arr[max])
max = left;
if (right < x && arr[right] > arr[max])
max = right;
if (max != y)
{
swap(&arr[y], &arr[max]);
print_array(arr, size);
heap(arr, x, max, size);
}
}

/**
 * heap_sort - sorts an array of ints in ascending order
 * @array: unordered array
 * @size: number of items in the array
 */

void heap_sort(int *array, size_t size)
{
int i;
for (i = size / 2 - 1; i >= 0; i--)
heap(array, size, i, size);

for (i = size - 1; i >= 0; i--)
{
swap(&array[0], &array[i]);
if (i != 0)
print_array(array, size);
heap(array, i, 0, size);
}
}
