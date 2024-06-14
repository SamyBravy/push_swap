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

void	sort_3(t_data *ab)
{
	if (!is_sorted(&ab->a, 0))
	{
		if (sorted_pos(&ab->a, s_len(&ab->a) - 1, ab) == ab->a.head)
		{
			if (!is_sorted(&ab->b, 0))
				rotate_s(&ab->a);
			else
				rotate_ab(&ab->a, &ab->b);
		}
		else if (sorted_pos(&ab->a, s_len(&ab->a) - 1, ab)
			!= (ab->a.tail - 1 + ab->a.size) % ab->a.size)
		{
			if (!is_sorted(&ab->b, 0))
				reverse_rotate_s(&ab->a);
			else
				reverse_rotate_ab(&ab->a, &ab->b);
		}
		if (sorted_pos(&ab->a, 0, ab) != ab->a.head)
		{
			if (!is_sorted(&ab->b, 0))
				swap_s(&ab->a);
			else
				swap_ab(&ab->a, &ab->b);
		}
	}
}

void	sort_5(t_data *ab)
{
	int		d_tail;
	int		i;

	i = sorted_pos(&ab->a, 1, ab);
	if (dist_top(&ab->a, sorted_pos(&ab->a, 0, ab), &d_tail)
		<= dist_top(&ab->a, sorted_pos(&ab->a, 1, ab), &d_tail))
		i = sorted_pos(&ab->a, 0, ab);
	i_at_top(&ab->a, i);
	if (!is_sorted(&ab->a, 0))
	{
		push_s(&ab->b, &ab->a);
		i = sorted_pos(&ab->a, 0, ab);
		i_at_top(&ab->a, i);
		push_s(&ab->b, &ab->a);
		sort_3(ab);
		if (is_sorted(&ab->b, 0))
			swap_s(&ab->b);
		push_s(&ab->a, &ab->b);
		push_s(&ab->a, &ab->b);
	}
}

void	sort_n(t_data *ab)
{
	int		i;
	int		min_moves;

	put_final_position(&ab->a, ab);
	min_moves = -42;
	while (moves_number(&ab->a, &ab->b, min_moves))
	{
		while (better_pb_init(ab))
			push_s(&ab->b, &ab->a);
		min_moves = ab->a.size - 2;
		i = -1;
		while (++i < ab->a.size - 2)
		{
			if (!moves_number(&ab->a, &ab->b, min_moves)
				|| (moves_number(&ab->a, &ab->b, i)
					< moves_number(&ab->a, &ab->b, min_moves)
					&& moves_number(&ab->a, &ab->b, i)))
				min_moves = i;
		}
		put_next(&ab->a, &ab->b, min_moves,
			total_moves_if(&ab->a, &ab->b, min_moves, 0)
			< total_moves_if(&ab->a, &ab->b, min_moves, 1));
	}
	while (ab->b.head != ab->b.tail)
		push_s(&ab->a, &ab->b);
}
