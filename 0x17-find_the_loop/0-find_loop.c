#include "lists.h"
/**
 * find_listint_loop - function to find loop in a linked list
 * @head: ptr to linked list
 * Return: address of node where the loop begins or NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
listint_t *i = head;
listint_t *j = head;

if (!head)
return (NULL);
while (i->next && j->next->next)
{
i = i->next;
j = j->next->next;
if (i == j)
{
i = head;
while (i != j)
{
i = i->next;
j = j->next;
}
return (j);
}
}
return (NULL);
}
