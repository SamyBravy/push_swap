/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:49:48 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/18 18:59:15 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_s(t_stack *s)
{
	swap(s);
	if (s->name == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	push_s(t_stack *s1, t_stack *s2)
{
	push(s1, s2);
	if (s1->name == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	rotate_s(t_stack *s)
{
	rotate(s);
	if (s->name == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	reverse_rotate_s(t_stack *s)
{
	reverse_rotate(s);
	if (s->name == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
