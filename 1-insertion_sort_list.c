#include <stdio.h>
#include "sort.h"

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
