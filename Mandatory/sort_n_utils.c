/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:46:44 by sdell-er          #+#    #+#             */
/*   Updated: 2024/04/10 17:22:01 by sdell-er         ###   ########.fr       */
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

int	moves_sum(t_stack *a, t_stack *b, int min_moves, int choice)
{
	t_stack	temp_a;
	t_stack	temp_b;
	int		moves_sum;
	int		i;

	clone_stack(&temp_a, a);
	if (!temp_a.buffer)
		exit_error(a, b);
	clone_stack(&temp_b, b);
	if (!temp_b.buffer)
	{
		free(temp_b.buffer);
		exit_error(a, b);
	}
	put_next(a, &b, min_moves, choice);
	i = 0;
	moves_sum = 0;
	if (is_present(b, (min_moves + 1 * choice) % (a->size - 1))
		&& is_present(a, (min_moves + 1 - choice) % (a->size - 1)))
		moves_sum++;
	while (i < a->size)
		moves_sum += moves_number(a, b, i++);
	free(temp_a.buffer);
	free(temp_b.buffer);
	return (moves_sum);
}

void	put_final_position(t_stack *s)
{
	int		i;
	t_stack	temp;

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

int	better_move(t_stack *a, t_stack *b)
{
	
}
