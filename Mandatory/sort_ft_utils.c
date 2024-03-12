/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:10:49 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/19 20:47:15 by sdell-er         ###   ########.fr       */
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

int	i_2min(t_stack *s)
{
	int	index_min;
	int	i;

	if (i_min(s) != s->head)
	{
		index_min = s->head;
		i = (s->head + 1) % s->size;
	}
	else
	{
		index_min = (s->head + 1) % s->size;
		i = (s->head);
	}
	while (i != s->tail && index_min != s->tail)
	{
		if (s->buffer[i] < s->buffer[index_min] && i_min(s) != i)
			index_min = i;
		i = (i + 1) % s->size;
	}
	if (index_min == s->tail)
		index_min = i_min(s);
	return (index_min);
}

int	dist_top(t_stack *s, int i, int *d_tail)
{
	int	d1;
	int	d2;

	*d_tail = 1;
	d1 = (s->tail - i + s->size) % s->size;
	d2 = (i - s->head + s->size) % s->size;
	if (d1 <= d2)
		return (d1);
	*d_tail = 0;
	return (d2);
}

void	i_at_top(t_stack *a, int i)
{
	int	d_tail;

	while (dist_top(a, i, &d_tail))
	{
		if (d_tail)
			reverse_rotate_a(a);
		else
			rotate_a(a);
	}
}
