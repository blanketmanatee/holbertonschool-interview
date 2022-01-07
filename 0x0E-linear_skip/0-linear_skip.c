#include "search.h"

/**
 * linear_skip - search for value in sorted skip list
 * @list: ptr to head of skip list
 * @value: value to search for
 * Return: ptr to first node or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *node;
if (!list)
return (NULL);

node = list->express;
printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
while (node && node->n < value)
{
list = node;
node = node->express;
if (!node)
{
node = list;
while (node->next)
node = node->next;
break;
}
printf("Value checked at index [%lu] and [%d]\n", node->index, node->n);
}
printf("Value found between indexes[%lu] and [%lu]\n", list->index,
node->index);
for (; list && node->n >= list->n; list = list->next)
{
printf("value checked at index [%lu] = [%d]\n", list->index, list->n);
if (list->n == value)
return (list);
}
return (NULL);
}
