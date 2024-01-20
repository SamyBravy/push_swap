/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:53:38 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/20 19:49:01 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a, t_stack *b)
{
	if (!is_sorted(a))
	{
		if (i_max(a) == a->head)
		{
			if (!is_sorted(b))
				rotate_a(a);
			else
				rotate_ab(a, b);
		}
		else if (i_max(a) != (a->tail - 1 + a->size) % a->size)
		{
			if (!is_sorted(b))
				reverse_rotate_a(a);
			else
				reverse_rotate_ab(a, b);
		}
		if (i_min(a) != a->head)
		{
			if (!is_sorted(b))
				swap_a(a);
			else
				swap_ab(a, b);
		}
	}
}

void	sort_5(t_stack *a)
{
	t_stack	b;
	int		d_tail;
	int		i;

	if (!is_sorted(a))
	{
		init(&b, a->size);
		i = i_2min(a);
		if (dist_top(a, i_min(a), &d_tail) <= dist_top(a, i_2min(a), &d_tail))
			i = i_min(a);
		i_at_top(a, i);
		if (!is_sorted(a))
		{
			push_b(a, &b);
			i = i_min(a);
			i_at_top(a, i);
			push_b(a, &b);
			sort_3(a, &b);
			push_a(a, &b);
			push_a(a, &b);
		}
		free(b.buffer);
	}
}

void	sort_100(t_stack *a)
{
	t_stack	b;

	if (!is_sorted(a))
	{
		init(&b, a->size);
		free(b.buffer);
	}
}

void	sort_500(t_stack *a)
{
	t_stack	b;

	if (!is_sorted(a))
	{
		init(&b, a->size);
		free(b.buffer);
	}
}
