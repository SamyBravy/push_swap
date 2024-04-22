/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:08:14 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/22 13:08:15 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
