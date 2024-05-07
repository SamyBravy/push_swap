/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:49:41 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/24 11:51:23 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	ft_atoi2(const char *str)
{
	int			i;
	int			n;
	long int	res;

	n = 0;
	i = 1;
	res = 0;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			i *= -1;
		n += 1;
	}
	while (str[n] >= '0' && str[n] <= '9')
		res = res * 10 + (str[n++] - '0');
	return (res * i);
}

void	init(t_stack *s, int size, char name, t_stack *s_tofree)
{
	s->buffer = malloc(size * sizeof(int));
	if (!s->buffer)
		exit_error(s_tofree, NULL);
	s->size = size;
	s->head = 0;
	s->tail = 0;
	s->name = name;
}

static void	expand_argv(t_stack *a, char ***argv, int *argc)
{
	if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		if (!*argv)
			exit_error(NULL, NULL);
		*argc = 0;
		while ((*argv)[*argc])
			(*argc)++;
		a->expanded = 1;
	}
	else
	{
		*argv = &((*argv)[1]);
		a->expanded = 0;
		(*argc)--;
	}
	init(a, *argc + 1, 'a', NULL);
}

static void	free_if(char ***argv, t_stack *a)
{
	int	i;

	if (a->expanded)
	{
		i = 0;
		while ((*argv)[i])
		{
			free((*argv)[i]);
			i++;
		}
		free(*argv);
	}
}

int	main(int argc, char **argv)
{
	t_data	ab;

	expand_argv(&ab.a, &argv, &argc);
	while (argc > 0)
	{
		if (index_n(&ab.a, ft_atoi2(argv[argc - 1]))
			|| !is_digit(argv[argc - 1]) || !is_int(ft_atoi2(argv[argc - 1])))
		{
			free_if(&argv, &ab.a);
			exit_error(&ab.a, NULL);
		}
		ab.a.head = (ab.a.head - 1 + ab.a.size) % ab.a.size;
		ab.a.buffer[ab.a.head] = ft_atoi2(argv[argc-- - 1]);
	}
	free_if(&argv, &ab.a);
	if (ab.a.size - 1 <= 3 && !is_sorted(&ab.a, 0))
		sort_3(&ab.a, NULL);
	else if (ab.a.size - 1 <= 5 && !is_sorted(&ab.a, 0))
		sort_5(&ab.a);
	else if (!is_sorted(&ab.a, 0))
		sort_n(&ab);
	free(ab.a.buffer);
	return (0);
}
