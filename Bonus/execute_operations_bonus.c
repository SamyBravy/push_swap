/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:19:36 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/18 17:01:08 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	execute2(t_stack *a, t_stack *b, char **op)
{
	if (ft_strcmp(*op, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(*op, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(*op, "rr\n") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(*op, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(*op, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(*op, "rrr\n") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
	{
		free(*op);
		free(b->buffer);
		exit_error(a);
	}
}

void	execute(t_stack *a, t_stack *b, char **op)
{
	if (ft_strcmp(*op, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(*op, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(*op, "ss\n") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(*op, "pa\n") == 0)
		push(a, b);
	else if (ft_strcmp(*op, "pb\n") == 0)
		push(b, a);
	else
		execute2(a, b, op);
	free(*op);
	*op = get_next_line(STDIN_FILENO);
}
