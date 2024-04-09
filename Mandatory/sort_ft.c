/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:53:38 by sdell-er          #+#    #+#             */
/*   Updated: 2024/03/12 18:21:08 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a, t_stack *b)
{
	if (!is_sorted(a, 0))
	{
		if (i_max(a) == a->head)
		{
			if (!is_sorted(b, 0))
				rotate_a(a);
			else
				rotate_ab(a, b);
		}
		else if (i_max(a) != (a->tail - 1 + a->size) % a->size)
		{
			if (!is_sorted(b, 0))
				reverse_rotate_a(a);
			else
				reverse_rotate_ab(a, b);
		}
		if (i_min(a) != a->head)
		{
			if (!is_sorted(b, 0))
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

	if (!is_sorted(a, 0))
	{
		init(&b, a->size, a);
		i = i_2min(a);
		if (dist_top(a, i_min(a), &d_tail) <= dist_top(a, i_2min(a), &d_tail))
			i = i_min(a);
		i_at_top(a, i);
		if (!is_sorted(a, 0))
		{
			push_b(a, &b);
			i = i_min(a);
			i_at_top(a, i);
			push_b(a, &b);
			sort_3(a, &b);
			if (is_sorted(&b, 0))
				swap_b(&b);
			push_a(a, &b);
			push_a(a, &b);
		}
		free(b.buffer);
	}
}

void	sort_100(t_stack *a)
{
	t_stack	b;
	int		i;
	int		min_moves;

	put_final_position(a);
	min_moves = -42;
	while (!is_sorted(a, 0) && a->head != a->tail
		|| !is_sorted(&b, 1) && b.head != b.tail
		|| moves_number(a, &b, min_moves))
	{
		init(&b, a->size, a);
		while (better_move(a, &b))
			push_b(a, &b);
		min_moves = a->size - 2;
		i = 0;
		while (i < a->size - 2)
		{
			if (moves_number(a, &b, min_moves) == 0)
				min_moves = i;
			else if (moves_number(a, &b, i) < moves_number(a, &b, min_moves)
				&& moves_number(a, &b, i) != 0)
				min_moves = i;
			i++;
		}
		if (moves_sum(a, &b, min_moves, 0) < moves_sum(a, &b, min_moves, 1))
			put_next(a, &b, min_moves, 0);
		else
			put_next(a, &b, min_moves, 1);
		free(b.buffer);
	}
	while (b.head != b.tail)
		push_a(a, &b);
}
