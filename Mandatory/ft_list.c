#include "push_swap.h"

void	insert_last(t_lst **list, void *value)
{
	while (*list)
		list = &(*list)->next;
	*list = malloc(sizeof(t_lst));
	(*list)->value = value;
	(*list)->next = NULL;
}

void	free_list(t_lst **list)
{
	t_lst	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}
