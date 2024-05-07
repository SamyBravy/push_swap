/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:55:25 by sdell-er          #+#    #+#             */
/*   Updated: 2024/05/07 11:47:24 by anomourn         ###   ########.fr       */
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

static void	clone_2_stack(t_stack *a, t_stack *b, t_stack *t_a, t_stack *t_b)
{
	clone_stack(t_a, a);
	if (!t_a->buffer)
		exit_error(a, b);
	clone_stack(t_b, b);
	if (!t_a->buffer)
	{
		free(t_a->buffer);
		exit_error(a, b);
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

int	index_n(t_stack *s, int value)
{
	int	i;

	i = s->head;
	while (i != s->tail)
	{
		if (s->buffer[i] == value)
			return ((i - s->head + s->size) % s->size + 1);
		i = (i + 1) % s->size;
	}
	return (0);
}

int	total_moves_if(t_stack *a, t_stack *b, int min_moves, int choice)
{
	t_stack	temp_a;
	t_stack	temp_b;
	int		moves_sum;

	clone_2_stack(a, b, &temp_a, &temp_b);
	moves_sum = 0;
	if (index_n(b, (min_moves + 1 * choice) % (a->size - 1))
		&& index_n(a, (min_moves + 1 - choice) % (a->size - 1)))
		moves_sum++;
	moves_sum += put_next(&temp_a, &temp_b, min_moves, choice + 2);
	moves_sum += total_moves(&temp_a, &temp_b);
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
	push_s(b, a);
	better_move = total_moves(a, b) + 1 < tot_moves;
	free(a->buffer);
	free(b->buffer);
	clone_2_stack(a, b, &temp_a, &temp_b);
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

	clone_2_stack(a, b, &temp_a, &temp_b);
	return (better_pb(&temp_a, &temp_b, a, b));
}

int	moves_number(t_stack *a, t_stack *b, int link)
{
	t_stack	temp_a;
	t_stack	temp_b;
	int		moves_0;
	int		moves_1;

	if (link < 0)
		return (-42);
	clone_2_stack(a, b, &temp_a, &temp_b);
	moves_0 = put_next(&temp_a, &temp_b, link, 2);
	free(temp_a.buffer);
	free(temp_b.buffer);
	clone_2_stack(a, b, &temp_a, &temp_b);
	moves_1 = put_next(&temp_a, &temp_b, link, 3);
	if (moves_1 < moves_0)
		moves_0 = moves_1;
	free(temp_a.buffer);
	free(temp_b.buffer);
	return (moves_0);
}

void	insert_last(t_lst **list, void *value)
{
	t_lst	*l;

	l = malloc(sizeof(t_lst));
	if (!l)
		// aiuto
	l->value = value;
	l->next = NULL;
	while (*list)
		list = &(*list)->next;
	*list = l;
}

static void	be_top_down(t_stack *s, t_lst *op_s, int value, int down)
{
	int	i;
	int	d_tail;
	int	dist;

	dist = dist_top(s, index_n(s, value) - 1, &d_tail);
	i = 0;
	while (i < dist + (!d_tail - d_tail) && down)
	{
		if (d_tail)
			insert_last(&op_s, reverse_rotate_s);
		else
			insert_last(&op_s, rotate_s);
		i++;
	}
}

static t_2lst	*op_diff_stacks(t_stack *a, t_stack *b, int link, int choice)
{
	t_lst	*op_a;
	t_lst	*op_b;
	t_2lst	*op_ab;

	op_a = NULL;
	op_b = NULL;
	if ((index_n(a, link) && !(choice % 2))
		|| (index_n(b, link) && choice % 2))
	{
		be_top_down(b, op_b, (link + !(choice % 2)) % (a->size - 1), 0);
		be_top_down(a, op_a, (link + choice % 2)
			% (a->size - 1), !(choice % 2));
		insert_last(&op_a, push_s);
	}
	else
	{
		be_top_down(a, op_a, (link + !(choice % 2)) % (a->size - 1), 0);
		be_top_down(b, op_b, (link + choice % 2)
			% (a->size - 1), choice % 2);
		insert_last(&op_b, push_s);
	}
	op_ab = malloc(sizeof(t_2lst));
	if (!op_ab)
		// aiuto
	op_ab->l1 = op_a;
	op_ab->l2 = op_b;
	return (op_ab);
}

static int	dist_i_j(t_stack *a, t_stack *b, int link)
{
	int	dist_1;
	int	dist_2;

	dist_1 = index_n(a, link) - index_n(a, (link + 1) % (a->size - 1));
	dist_2 = index_n(b, link) - index_n(b, (link + 1) % (b->size - 1));
	if (dist_1 && dist_2 && a != b)
		return (0);
	if (dist_1 < 0)
		dist_1 *= -1;
	else if (dist_2 < 0)
		dist_2 *= -1;
	if (dist_1 != 0)
		return (dist_1);
	return (dist_2);
}

static void	op_next(t_stack *s, t_lst *op_s, int link, int choice)
{
	(void)s;
	(void)op_s;
	(void)link;
	(void)choice;
}

static void	op_far(t_stack *s, t_lst *op_s, int link, int choice)
{
	(void)s;
	(void)op_s;
	(void)link;
	(void)choice;
}

static void	op_same_stack(t_stack *s, t_lst *op_s, int link, int choice)
{
	if (dist_i_j(s, s, link) == 1)
	{
		if (index_n(s, link) < index_n(s, (link + 1) % (s->size - 1)))
			return ;
	}
	if (dist_i_j(s, s, link) - 1 <= 3)
		op_next(s, op_s, link, choice);
	else
		op_far(s, op_s, link, choice);
}

int	put_next(t_stack *a, t_stack *b, int link, int choice)
{
	int				moves;
	static t_lst	*op_a = NULL;
	static t_lst	*op_b = NULL;

	if (dist_i_j(a, b, link) == 0)
	{
		op_a = op_diff_stacks(a, b, link, choice)->l1; // bisogna fare il free di op_ab
		op_b = op_diff_stacks(a, b, link, choice)->l2; // bisogna fare il free di op_ab
	}
	else
	{
		if (index_n(a, link))
			op_same_stack(a, op_a, link, choice);
		else
			op_same_stack(b, op_b, link, choice);
	}
	moves = 0;
	// faire les movements combinés quand c'est possible
	// ...
	return (moves);
}
