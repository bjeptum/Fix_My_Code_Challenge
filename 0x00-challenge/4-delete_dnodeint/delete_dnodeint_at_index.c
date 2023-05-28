#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
    dlistint_t *current;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
    current = saved_head;
    if (index == 0)
    {
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }
    p = 0;
    while (p < index && current != NULL)
    {
        current = current->next;
        p++;
    }
    if (p != index)
    {
        *head = saved_head;
        return (-1);
    }
    if (current == NULL || current->next == NULL)
        return (-1);
    tmp = current->next;
    current->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = current;
    free(tmp);
    *head = saved_head;
    return (1);
}
