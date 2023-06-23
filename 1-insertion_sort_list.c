#include <stdio.h>
#include "sort.h"

/**
 * swap - swap nodes
 * @prevList: first node
 * @nextList: second node
*/

void swap(listint_t *prevList, listint_t *nextList)
{
	listint_t *temp1, *temp2;

	temp1 = nextList->next;
	temp2 = prevList->prev;

	prevList->next = temp1;
	nextList->prev = temp2;

	prevList->prev = nextList;
	nextList->next = prevList;

	if (temp1 != NULL)
		temp1->prev = prevList;
	if (temp2 != NULL)
		temp2->next = nextList;
}

/**
 * insertion_sort_list - sort list
 * @list: pointer to list head
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *p1;
	listint_t *p2;

	if (*list == NULL || list == NULL)
		return;
	p1 = (*list)->next;
	while (p1 != NULL)
	{
		p2 = p1;
		p1 = p1->next;
		while (p2->prev && p2->n < p2->prev->n)
		{
			swap(p2->prev, p2);
			if (p2->prev == NULL)
				*list = p2;
			print_list(*list);
		}
	}
}
