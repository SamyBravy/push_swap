/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:10:49 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/16 21:36:54 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	i_max(t_stack *s)
{
	int	index_max;
	int	i;

	index_max = s->head;
	i = (s->head + 1) % s->size;
	while (i != s->tail)
	{
		if (s->buffer[i] > s->buffer[index_max])
			index_max = i;
		i = (i + 1) % s->size;
	}
	return (index_max);
}

int	i_min(t_stack *s)
{
	int	index_min;
	int	i;

	index_min = s->head;
	i = (s->head + 1) % s->size;
	while (i != s->tail)
	{
		if (s->buffer[i] < s->buffer[index_min])
			index_min = i;
		i = (i + 1) % s->size;
	}
	return (index_min);
}

int	i_value(t_stack *s, int i)
{
	if ((s->tail - s->head + s->size) % s->size > i)
		return (s->buffer[(s->head + i) % s->size]);
	return (-1);
}
