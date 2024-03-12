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

void	swap_a(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	push_a(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
