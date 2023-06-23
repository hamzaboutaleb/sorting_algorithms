#include "sort.h"
#include <stdio.h>

/**
 * swap - swap to elemnt
 * @prevList: first list
 * @nextList: second list
*/
void swap(listint_t *prevList, listint_t *nextList)
{
	listint_t *temp1 = NULL, *temp2 = NULL;

	if (nextList->next)
		temp1 = nextList->next;
	if (prevList->prev)
		temp2 = prevList->prev;

	prevList->next = temp1;
	nextList->prev = temp2;

	prevList->prev = nextList;
	nextList->next = prevList;

	if (temp1)
		temp1->prev = prevList;
	if (temp2)
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
		while (p2 && p2->prev)
		{
			if (p2->n < p2->prev->n)
			{
				swap(p2->prev, p2);
				if (p2->prev == NULL)
					*list = p2;
				print_list(*list);
				continue;
			}
			else
				break;
		}
		p1 = p1->next;
	}
}
