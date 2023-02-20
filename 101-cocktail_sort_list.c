#include "sort.h"
/**
 * swap_node_ahead - A fuunction that swaps a node from the beginning
 * @list: head ref of the linked list
 * @start: The start of the list to be swapped
 * @end: The end of the list to be swapped
 */
void swap_node_ahead(listint_t **list, listint_t **end, listint_t **start)
{
	listint_t *tmp = (*start)->next;

	if ((*start)->prev != NULL)
		(*start)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*start)->prev;
	(*start)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *start;
	else
		*end = *start;
	(*start)->prev = tmp;
	tmp->next = *start;
	*start = tmp;
}

/**
 * swap_node_behind - A fuunction that swaps a node from the ending
 * @list: head ref of the linked list
 * @start: The start of the list to be swapped
 * @end: The end of the list to be swapped
 */
void swap_node_behind(listint_t **list, listint_t **end, listint_t **start)
{
	listint_t *tmp = (*start)->prev;

	if ((*start)->next != NULL)
		(*start)->next->prev = tmp;
	else
		*end = tmp;
	tmp->next = (*start)->next;
	(*start)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *start;
	else
		*list = *start;
	(*start)->next = tmp;
	tmp->prev = *start;
	*start = tmp;
}

/**
 * cocktail_sort_list - A function that sorts a doubly linked list of integers
 *			in ascending order using the Cocktail shaker sort algorithm
 * @list: The doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	bool swapped = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (end = *list; end->next != NULL;)
		end = end->next;
	while (swapped == false)
	{
		swapped = true;
		for (start = *list; start != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_node_ahead(list, &end, &start);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
		for (start = start->prev; start != *list; start = start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_node_behind(list, &end, &start);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
	}
}
