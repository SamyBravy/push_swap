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
	int	n;

	n = dist_top(a, i, &d_tail);
	while (n-- > 0)
	{
		if (d_tail)
			reverse_rotate_a(a);
		else
			rotate_a(a);
	}
}

static void	bubble_sort(int *arr, int dim)
{
	int	i;
	int	j;
	int	temp;
	int	swapped;

	i = 0;
	swapped = 1;
	while (i < dim - 1 && swapped)
	{
		swapped = 0;
		j = 0;
		while (j < dim - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}

int	sorted_pos(t_stack *s, int n, t_stack *s_to_free)
{
	int		*arr;
	int		i;

	arr = malloc((s_len(s)) * sizeof(int));
	if (!arr)
		exit_error(s, s_to_free);
	i = 0;
	while ((s->head + i) % s->size != s->tail)
	{
		arr[i] = s->buffer[(s->head + i) % s->size];
		i++;
	}
	bubble_sort(arr, s_len(s));
	i = s->head;
	while (i != s->tail)
	{
		if (s->buffer[i] == arr[n])
		{
			free(arr);
			return (i);
		}
		i = (i + 1) % s->size;
	}
	free(arr);
	return (-42);
}

int	s_len(t_stack *s)
{
	return ((s->tail - s->head + s->size) % s->size);
}
