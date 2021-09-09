#include "lists.h"

/**
 * check_cycle - check if a singlly linked list has a cycle
 * @list: pointer to list head
 * Return: 0 if no cycle, or 1
 */

int check_cycle(listint_t *list)
{
    listint_t *first, *second;

    if (list == NULL)
            return (0);
    if (list->next == NULL)
            return (0);
        first = list;
        second = list->next;
        do {
            if (first == second)
                return (1);
            first = first->next;
            if (second->next != NULL)
                second = second->next->next;
            else
                second = NULL;
        } while (first != NULL && second != NULL);
        return (0);
}
