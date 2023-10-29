#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 0;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                print_list(*list);
                swapped = 1;
            }
        }
    } while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 * @node1: First node to swap.
 * @node2: Second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    listint_t *temp_prev, *temp_next;

    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;

    temp_prev = node1->prev;
    temp_next = node2->next;

    node1->prev = node2;
    node1->next = temp_next;
    node2->prev = temp_prev;
    node2->next = node1;

    if (temp_next != NULL)
        temp_next->prev = node1;

    if (temp_prev != NULL)
        temp_prev->next = node2;
}
