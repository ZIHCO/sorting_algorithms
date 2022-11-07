#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: unsorted list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *node, *next_node, *prev_node;

	tmp = *list;
	while (tmp)
	{
		node = tmp->next;
		while (node)
		{
			if ((node->n) >= ((node->prev)->n))
				node = node->next;
			else if (!(node->next) && !((node->prev)->prev))
			{
				swap_two(node);
				*list = node;
				print_list(node);
				node = node->next;
			}
			else
			{
				prev_node = node->prev;
				next_node = node->next;
				if (prev_node->prev && next_node)
					swap_node(node);
				else if (prev_node->prev == NULL)
				{
					swap_start(node);
					*list = node;
					node = node->next;
				}
				else if (next_node == NULL)
					swap_end(node);
				print_list(*list);
			}
		}
		tmp = tmp->next;
	}
}

/**
 * swap_end - swap end node
 * @node: node to swap
 * Return: nothing
 */

void swap_end(listint_t *node)
{
	listint_t *prev_node = node->prev;

	(prev_node->next) = NULL;
	node->prev = prev_node->prev;
	(prev_node->prev)->next = node;
	prev_node->prev = node;
	node->next = prev_node;
	node = node->next;
}

/**
 * swap_start - swap start node
 * @node: node to swap
 * Return: nothing
 */

void swap_start(listint_t *node)
{
	listint_t *prev_node = node->prev;
	listint_t *next_node = node->next;

	(prev_node->next) = next_node;
	prev_node->prev = node;
	node->prev = NULL;
	(next_node->prev) = prev_node;
	node->next = prev_node;
}

/**
 * swap_two - swap two nodes list
 * @node: node to swap
 * Return: nothing
 */

void swap_two(listint_t *node)
{
	listint_t *tmp = node->prev;

	tmp->prev = node;
	node->next = tmp;
	tmp->next = NULL;
	node->prev = NULL;
}

/**
 * swap_node - swap this node
 * @node: node to swap
 * Return: nothing
 */

void swap_node(listint_t *node)
{
	listint_t *prev_node = node->prev;
	listint_t *next_node = node->next;

	(prev_node->next) = next_node;
	node->prev = prev_node->prev;
	(prev_node->prev)->next = node;
	(next_node->prev) = prev_node;
	prev_node->prev = node;
	node->next = prev_node;
}
