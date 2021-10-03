#include "lists.h"

/**
 * reverse - rev nodes
 * @head: head of list
 * Return: ptr to first node
 */

listint_t *reverse(listint_t *head)
{
    listint_t *t = head;
    listint_t *crr = head;
    listint_t *prev = NULL;

    while (t)
    {
        t = crr->next;
        crr->next = prev;
        prev = crr;
        crr = t;
    }
    return (prev);
}
/**
 * is_palindrome - checks if singly linked list is palindrome
 * Return: 0 if not, 1 if it is
 */

int is_palindrome(listint_t **head)
{
    listint_t *s, *f, *crr, *rev;

    crr = *head;
    s = *head;
    f = *head;
    while (crr && f->next && f->next->next)
    {
        s = s->next;
        f = f->next->next;
    }
    rev = reverse(s);
    while (rev && crr)
    {
        if (rev->n != crr->n)
        return (0);

        rev = rev->next;
        crr = crr->next;
    }
    return(1);
}
