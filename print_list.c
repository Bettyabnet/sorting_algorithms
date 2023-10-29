#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a doubly linked list of integers
 *
 * @list: Pointer to the head of the doubly linked list
 */
void print_list(const listint_t *list)
{
    const listint_t *node = list;

    while (node != NULL)
    {
        printf("%d", node->n);
        if (node->next != NULL)
            printf(", ");
        node = node->next;
    }
    printf("\n");
}
