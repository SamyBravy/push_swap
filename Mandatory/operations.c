/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:13:22 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/19 20:43:17 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	int	tmp;

	if (s_len(s) >= 2)
	{
		tmp = s->buffer[s->head];
		s->buffer[s->head] = s->buffer[(s->head + 1) % s->size];
		s->buffer[(s->head + 1) % s->size] = tmp;
	}
}

void	push(t_stack *s1, t_stack *s2)
{
	if ((s2->tail - s2->head + s2->size) % s2->size > 0)
	{
		s1->head = (s1->head - 1 + s1->size) % s1->size;
		s1->buffer[s1->head] = s2->buffer[s2->head];
		s2->head = (s2->head + 1) % s2->size;
	}
}

void	rotate(t_stack *s)
{
	s->buffer[s->tail] = s->buffer[s->head];
	s->tail = (s->tail + 1) % s->size;
	s->head = (s->head + 1) % s->size;
}

void	reverse_rotate(t_stack *s)
{
	s->head = (s->head - 1 + s->size) % s->size;
	s->tail = (s->tail - 1 + s->size) % s->size;
	s->buffer[s->head] = s->buffer[s->tail];
}
