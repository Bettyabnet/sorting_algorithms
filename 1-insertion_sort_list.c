#include <stdio.h>
#include "sort.h"

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}


/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using
 *                        the Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr = (*list)->next;

    while (curr != NULL)
    {
        listint_t *temp = curr->next;
        listint_t *prev = curr->prev;

        while (prev != NULL && prev->n > curr->n)
        {
            prev->next = curr->next;

            if (curr->next != NULL)
                curr->next->prev = prev;

            curr->prev = prev->prev;
            curr->next = prev;
            
            if (prev->prev != NULL)
                prev->prev->next = curr;
            else
                *list = curr;

            prev->prev = curr;
            prev = curr->prev;
            print_list(*list);
        }

        curr = temp;
    }
}
