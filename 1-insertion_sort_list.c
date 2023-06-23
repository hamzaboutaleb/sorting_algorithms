#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: Double pointer to the head of the linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *next_node, *temp;

	if (list == NULL || *list == NULL)
		return;
	node = (*list)->next;
	while (node != NULL)
	{
		next_node = node->next;
		while (node->prev != NULL && node->prev->n > node->n)
		{
			temp = node->prev;
			temp->next = node->next;
			node->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = node;
			else
				*list = node;
			if (node->next)
				node->next->prev = temp;
			node->next = temp;
			temp->prev = node;
			print_list(*list);
		}
		node = next_node;
	}
}
