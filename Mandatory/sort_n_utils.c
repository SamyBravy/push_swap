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

static int	index_n(t_stack *s, int value)
{
	int	i;

	i = s->head;
	while (i != s->tail)
	{
		if (s->buffer[i] == value)
			return ((i - s->head + s->size) % s->size);
		i = (i + 1) % s->size;
	}
	return (-42);
}

int	total_moves_if(t_stack *a, t_stack *b, int min_moves, int choice)
{
	t_stack	temp_a;
	t_stack	temp_b;
	int		moves_sum;

	clone_2_stack(a, b, &temp_a, &temp_b);
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

void	to_be_at_top(t_stack *s, t_stack *op_s, int link, int choice)
{
	int	i;
	int	d_tail;

	// mettere l'elemento da spostare all'inizio del suo stack
	i = 0;
	while (i < dist_top(s, index_n(s, (link + choice % 2 == (s->name == 'a'))
				% (a->size - 1)), &d_tail))
	{
		if (d_tail)
			insert_last(op_s, reverse_rotate_s);
		else
			insert_last(op_s, rotate_s);
		i++;
	}
	// mettere l'altro elemento all'inizio (o alla fine, dipende da quale è più grande e se siamo in a o in b) del suo stack
	// ...
	insert_last(op_s, push_s);
}

int	put_next(t_stack *a, t_stack *b, int link, int choice)
{
	int		moves;
	t_lst	*op_a;
	t_lst	*op_b;

	op_a = NULL;
	op_b = NULL;
	//stack differentes
	if ((is_present(a, link) && is_present(b, (link + 1) % (a->size - 1)))
		|| (is_present(b, link) && is_present(a, (link + 1) % (a->size - 1))))
	{
		if ((is_present(a, link) && choice % 2 == 0)
			|| (is_present(b, link) && choice % 2 == 1))
			to_be_at_top(b, &op_b, link, choice);
		else
			to_be_at_top(a, &op_a, link, choice);
	} // fin stack differentes
	else // meme stack
	{

	}
	
	moves = 0;
	free_list(&op_a);
	free_list(&op_b);
	return (moves);
}
