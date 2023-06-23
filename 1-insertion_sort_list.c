#include <stdio.h>
#include "sort.h"

/**
 * swap - swap nodes
 * @prevList: first node
 * @nextList: second node
 * @list: pointer to head
*/

void swap(listint_t *prevList, listint_t *nextList, listint_t **list)
{
	prevList->next = nextList->next;
	nextList->prev = prevList->prev;

	if (nextList->next)
		nextList->next->prev = prevList;
	if (prevList->prev)
		prevList->prev->next = nextList;
	else
		*list = nextList;
	prevList->prev = nextList;
	nextList->next = prevList;
}

/**
 * insertion_sort_list - sort list
 * @list: pointer to list head
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *p1;
	listint_t *p2;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;
	p1 = (*list)->next;
	while (p1 != NULL)
	{
		p2 = p1;
		p1 = p1->next;
		while (p2->prev && p2->n < p2->prev->n)
		{
			swap(p2->prev, p2, list);
			if (p2->prev == NULL)
				*list = p2;
			print_list(*list);
		}
	}
}
