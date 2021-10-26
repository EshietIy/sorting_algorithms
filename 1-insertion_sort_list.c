#include "sort.h"
/**
 * swap_nodes - swaps nodes in a doubly linked list
 * @a: first node
 * @b: second node
 */
void swap_nodes(listint_t *a, listint_t *b)
{
if (a == b)
return;
a->next = b->next;
b->prev = a->prev;
if (a->next != NULL)
a->next->prev = a;
if (b->prev != NULL)
b->prev->next = b;
b->next = a;
a->prev = b;
}

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * using the insertion sort algorithm
 * @list: the head of the linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
listint_t *r1, *r2;
if (list == NULL || (*list) == NULL || (*list)->next == NULL)
return;
r1 = (*list)->next;
while (r1 != NULL)
{
if (r1->n < r1->prev->n)
{
r2 = r1;
while (r2->prev != NULL)
{
if (r2->prev->n > r2->n)
{
swap_nodes(r2->prev, r2);
if (r2->prev == NULL)
*list = r2;
print_list(*list);
}
else
r2 = r2->prev;
}
}
r1 = r1->next;
}
}
