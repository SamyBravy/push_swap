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
		if (sorted_pos(a, s_len(a) - 1, b) == a->head)
		{
			if (!is_sorted(b, 0))
				rotate_s(a);
			else
				rotate_ab(a, b);
		}
		else if (sorted_pos(a, s_len(a) - 1, b)
			!= (a->tail - 1 + a->size) % a->size)
		{
			if (!is_sorted(b, 0))
				reverse_rotate_s(a);
			else
				reverse_rotate_ab(a, b);
		}
		if (sorted_pos(a, 0, b) != a->head)
		{
			if (!is_sorted(b, 0))
				swap_s(a);
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

	i = sorted_pos(a, 1, NULL);
	if (dist_top(a, sorted_pos(a, 0, NULL), &d_tail)
		<= dist_top(a, sorted_pos(a, 1, NULL), &d_tail))
		i = sorted_pos(a, 0, NULL);
	i_at_top(a, i);
	if (!is_sorted(a, 0))
	{
		init(&b, a->size, 'b', a);
		push_s(&b, a);
		i = sorted_pos(a, 0, &b);
		i_at_top(a, i);
		push_s(&b, a);
		sort_3(a, &b);
		if (is_sorted(&b, 0))
			swap_s(&b);
		push_s(a, &b);
		push_s(a, &b);
	}
	free(b.buffer);
}

void	sort_n(t_stack *a)
{
	t_stack	b;
	int		i;
	int		min_moves;

	put_final_position(a);
	init(&b, a->size, 'b', a);
	min_moves = -42;
	while (moves_number(a, &b, min_moves))
	{
		while (better_pb_init(a, &b))
			push_s(&b, a);
		min_moves = a->size - 2;
		i = -1;
		while (++i < a->size - 2)
		{
			if (!moves_number(a, &b, min_moves) || (moves_number(a, &b, i)
					< moves_number(a, &b, min_moves) && moves_number(a, &b, i)))
				min_moves = i;
		}
		put_next(a, &b, min_moves, total_moves_if(a, &b, min_moves, 0)
			< total_moves_if(a, &b, min_moves, 1));
	}
	while (b.head != b.tail)
		push_s(a, &b);
	free(b.buffer);
}
