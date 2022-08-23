#include "sort.h"
/**
 *
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur = (*list)->next;

	if (list == NULL)
		return;

	while (cur != NULL)
	{
		while (cur->n < cur->prev->n && cur->prev != NULL)
		{
			cur->prev->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = cur->prev;
			cur->next = cur->prev;
			cur->prev = cur->next->prev;
			cur->next->prev = cur;
			if (cur->prev == NULL)
				*list = cur;
			else
				cur->prev->next = cur;
			print_list(*list);
		}
		cur = cur->next;
	}
}
