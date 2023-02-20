#include "sort.h"

/**
 * swap_nodes - Swaps between two nodes
 * @head: Head ref to the list
 * @node1: Node to be swapped
 * @node2: Node to be swapped
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - A function that sorts a doubly linked list
 *	of integers in ascending order using the Insertion sort algorithm
 * @list: Linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *insert, *iter, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
