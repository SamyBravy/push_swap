/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:17:42 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/24 11:49:20 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static void	init(t_stack *s, int size)
{
	s->buffer = malloc(size * sizeof(int));
	s->size = size;
	s->head = 0;
	s->tail = 0;
}

static void	add_a(t_stack *a, int *argc, char ***argv)
{
	if (is_present(a, ft_atoi2((*argv)[*argc - 1]))
		|| !is_digit((*argv)[*argc - 1])
			|| !is_int(ft_atoi2((*argv)[*argc - 1])))
	{
		free_if(argv, a);
		exit_error(a);
	}
	a->head = (a->head - 1 + a->size) % a->size;
	a->buffer[a->head] = ft_atoi2((*argv)[*argc - 1]);
	(*argc)--;
}

static void	expand_argv(t_stack *a, char ***argv, int *argc)
{
	if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		if (!*argv)
			exit_error(NULL);
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
	init(a, *argc + 1);
	if (!a->buffer)
		exit_error(NULL);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*op;

	expand_argv(&a, &argv, &argc);
	while (argc > 0)
		add_a(&a, &argc, &argv);
	free_if(&argv, &a);
	init(&b, a.size);
	if (!b.buffer)
		exit_error(&a);
	op = get_next_line(STDIN_FILENO);
	while (op)
		execute(&a, &b, &op);
	if (is_sorted(&a) && b.head == b.tail)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a.buffer);
	free(b.buffer);
	return (0);
}
