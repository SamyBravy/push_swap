/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:15:32 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/19 20:48:23 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9') || i)
				return (0);
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_int(long int n)
{
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

int	is_sorted(t_stack *s, int ord)
{
	int	i;

	if (!s || s->head == s->tail)
		return (0);
	i = s->head;
	while (i != s->tail && (i + 1) % s->size != s->tail)
	{
		if ((s->buffer[i] > s->buffer[(i + 1) % s->size] && ord == 0)
			|| (s->buffer[i] < s->buffer[(i + 1) % s->size] && ord == 1))
			return (0);
		i = (i + 1) % s->size;
	}
	return (1);
}

static void	free_list(t_lst **l)
{
	t_lst	*tmp;

	while (*l)
	{
		tmp = *l;
		*l = (*l)->next;
		free(tmp);
	}
}

void	exit_error(t_data *ab)
{
	write(2, "Error\n", 6);
	if (ab)
	{
		free(ab->a.buffer);
		free(ab->b.buffer);
		free_list(&ab->op_a);
		free_list(&ab->op_b);
	}
	exit(EXIT_FAILURE);
}
