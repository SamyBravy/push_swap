/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:46:44 by sdell-er          #+#    #+#             */
/*   Updated: 2024/04/11 15:47:29 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clone_stack(t_stack *dst, t_stack *src)
{
	int	i;

	dst->size = src->size;
	dst->head = src->head;
	dst->tail = src->tail;
	dst->buffer = (int *)malloc(sizeof(int) * src->size);
	if (!dst->buffer)
		return ;
	i = src->head;
	while (i != src->tail)
	{
		dst->buffer[i] = src->buffer[i];
		i = (i + 1) % src->size;
	}
}

static int	total_moves(t_stack *a, t_stack *b)
{
	int	moves_sum;
	int	i;

	i = 0;
	moves_sum = 0;
	while (i < a->size - 1)
		moves_sum += moves_number(a, b, i++);
	return (moves_sum);
}

int	total_moves_if(t_stack *a, t_stack *b, int min_moves, int choice)
{
	t_stack	temp_a;
	t_stack	temp_b;
	int		moves_sum;

	clone_stack(&temp_a, a);
	if (!temp_a.buffer)
		exit_error(a, b);
	clone_stack(&temp_b, b);
	if (!temp_b.buffer)
	{
		free(temp_b.buffer);
		exit_error(a, b);
	}
	moves_sum = 0;
	if (is_present(b, (min_moves + 1 * choice) % (a->size - 1))
		&& is_present(a, (min_moves + 1 - choice) % (a->size - 1)))
		moves_sum++;
	put_next(&temp_a, &temp_b, min_moves, choice + 2);
	moves_sum = total_moves(&temp_a, &temp_b);
	free(temp_a.buffer);
	free(temp_b.buffer);
	return (moves_sum);
}

void	put_final_position(t_stack *s)
{
	t_stack	temp;
	int		i;

	clone_stack(&temp, s);
	if (!temp.buffer)
		exit_error(s, NULL);
	i = 0;
	while (i < s_len(s))
	{
		temp.buffer[sorted_pos(s, i, NULL)] = i;
		i++;
	}
	free(s->buffer);
	clone_stack(s, &temp);
	if (!temp.buffer)
		exit_error(&temp, NULL);
	free(temp.buffer);
}

static int	better_pb(t_stack *a, t_stack *b, t_stack *free1, t_stack *free2)
{
	t_stack	temp_a;
	t_stack	temp_b;
	int		tot_moves;
	int		better_move;

	tot_moves = total_moves(a, b);
	push_b(a, b);
	better_move = total_moves(a, b) + 1 < tot_moves;
	free(a->buffer);
	free(b->buffer);
	clone_stack(&temp_a, a);
	if (!temp_a.buffer)
		exit_error(free1, free2);
	clone_stack(&temp_b, b);
	if (!temp_a.buffer)
	{
		free(temp_a.buffer);
		exit_error(free1, free2);
	}
	if (better_move)
	{
		free(temp_a.buffer);
		free(temp_b.buffer);
	}
	return (better_move || better_pb(&temp_a, &temp_b, free1, free2));
}

int	better_pb_init(t_stack *a, t_stack *b)
{
	t_stack	temp_a;
	t_stack	temp_b;

	clone_stack(&temp_a, a);
	if (!temp_a.buffer)
		exit_error(a, b);
	clone_stack(&temp_b, b);
	if (!temp_a.buffer)
	{
		free(temp_a.buffer);
		exit_error(a, b);
	}
	return (better_pb(&temp_a, &temp_b, a, b));
}
