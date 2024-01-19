/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:49:48 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/19 20:07:59 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	push_b(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
