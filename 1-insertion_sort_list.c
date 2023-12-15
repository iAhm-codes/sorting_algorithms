#include <stdio.h>
#include "sort.h"

/**
  * insertion_sort_list - Sorts a doubly linked list
  * of integers in ascending order using
  * the Insertion sort algorithm.
  *
  * @list: The doubly linked list to sort
  *
  * Return: Nothing
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *aux = NULL;
	bool flag = false;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	while (temp->next)
	{
		if (temp->n > temp->next->n)
		{
			temp->next->prev = temp->prev;
			if (temp->next->prev)
				temp->prev->next = temp->next;
			else
				*list = temp->next;

			temp->prev = temp->next;
			temp->next = temp->next->next;
			temp->prev->next = temp;
			if (temp->next)
				temp->next->prev = temp;

			temp = temp->prev;
			print_list(*list);

			if (temp->prev && temp->prev->n > temp->n)
			{
				if (!flag)
					aux = temp->next;
				flag = true;
				temp = temp->prev;
				continue;
			}
		}
		if (!flag)
			temp = temp->next;
		else
			temp = aux, flag = false;
	}
}
