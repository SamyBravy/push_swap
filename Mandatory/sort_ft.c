/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:53:38 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/18 19:16:32 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	int	index_max;
	int	index_min;

	if (!is_sorted(a))
	{
		index_max = i_max(a);
		if (index_max == a->head)
			rotate(a);
		else if (index_max != (a->tail - 1 + a->size) % a->size)
			reverse_rotate_a(a);
		index_min = i_min(a);
		if (index_min != a->head)
			swap_a(a);
	}
}

void	sort_5(t_stack *a)
{
	t_stack	b;

	if (!is_sorted(a))
	{
		init(&b, a->size);
		if (!b.buffer)
			exit_error(a);
		//	scorro fino a trovare il minimo o il secondo piu' piccolo
		push_b(a, &b);
		// scorro fino a trovare il minimo
		push_b(a, &b);
		// algoritmo per dim = 3 su a sfruttando le mosse doppie per ordinare b al contrario
		push_a(a, &b);
		push_a(a, &b);
		free(b.buffer);
	}
}

void	sort_100(t_stack *a)
{
	t_stack	b;

	if (!is_sorted(a))
	{
		init(&b, a->size);
		if (!b.buffer)
			exit_error(a);
		free(b.buffer);
	}
}

void	sort_500(t_stack *a)
{
	t_stack	b;

	if (!is_sorted(a))
	{
		init(&b, a->size);
		if (!b.buffer)
			exit_error(a);
		free(b.buffer);
	}
}
