#include "search_algos.h"

/**
 * print_array - print array
 * @array: array
 * @first: size
 * @last: value to find
 */

void print_array(int *array, int first, int last)
{
int i;

printf("Searching in array: ");
for (i = first; i < last; i++)
printf("%d, ", array[i]);
printf("\n");
}

/**
 * advanced_binary - advanced binary function
 * @array: array
 * @size: size
 * @value: value
 * Return: int
 */
int advanced_binary(int *array, size_t size, int value)
{
size_t first;
size_t last;

if (!array)
return (-1);
first = 0;
last = size - 1;
return (recursive_search(array, first, last, value));
}

/**
 * recursive_search - recursive search
 * @array: array
 * @first: ifirst
 * @last: last
 * @value: value
 * Return: int
 */
int recursive_search(int *array, size_t first, size_t last, int value)
{
size_t half;

if (first < last)
{
half = first + (last - first) / 2;
print_array(array, (int)first, (int)last);
if (array[half] >= value)
return (recursive_search(array, first, half, value));
else
return (recursive_search(array, half + 1, last, value));
return ((int)(half));
}
if (array[first] == value)
return (first);
print_array(array, (int)first, (int)last);
return (-1);
}
