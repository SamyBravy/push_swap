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

static void	init(t_data *ab, int size)
{
	ab->a.buffer = malloc(size * sizeof(int));
	if (!ab->a.buffer)
		return ;
	ab->a.size = size;
	ab->a.head = 0;
	ab->a.tail = 0;
	ab->a.name = 'a';
	ab->b.buffer = malloc(size * sizeof(int));
	ab->b.size = size;
	ab->b.head = 0;
	ab->b.tail = 0;
	ab->b.name = 'b';
	ab->op_a = NULL;
	ab->op_b = NULL;
}

static void	free_if(char ***argv, int expanded)
{
	int	i;

	if (expanded)
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

static void	expand_argv(t_data *ab, char ***argv, int *argc)
{
	if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		if (!*argv)
			exit_error(NULL);
		*argc = 0;
		while ((*argv)[*argc])
			(*argc)++;
		ab->expanded = 1;
	}
	else
	{
		*argv = &((*argv)[1]);
		ab->expanded = 0;
		(*argc)--;
	}
	init(ab, *argc + 1);
	if (!ab->a.buffer || !ab->b.buffer)
	{
		if (ab->a.buffer)
			free(ab->a.buffer);
		free_if(argv, ab->expanded);
		exit_error(NULL);
	}
}

int	main(int argc, char **argv)
{
	t_data	ab;

	expand_argv(&ab, &argv, &argc);
	while (argc > 0)
	{
		if (index_n(&ab.a, ft_atoi2(argv[argc - 1]))
			|| !is_digit(argv[argc - 1]) || !is_int(ft_atoi2(argv[argc - 1])))
		{
			free_if(&argv, ab.expanded);
			exit_error(&ab);
		}
		ab.a.head = (ab.a.head - 1 + ab.a.size) % ab.a.size;
		ab.a.buffer[ab.a.head] = ft_atoi2(argv[argc-- - 1]);
	}
	free_if(&argv, ab.expanded);
	if (ab.a.size - 1 <= 3 && !is_sorted(&ab.a, 0))
		sort_3(&ab);
	else if (ab.a.size - 1 <= 5 && !is_sorted(&ab.a, 0))
		sort_5(&ab);
	else if (!is_sorted(&ab.a, 0))
		sort_n(&ab);
	free(ab.a.buffer);
	free(ab.b.buffer);
	return (0);
}
