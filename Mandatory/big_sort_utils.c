/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:49:32 by sdell-er          #+#    #+#             */
/*   Updated: 2024/03/12 18:30:29 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr(int *arr, int dim, int *perm)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < dim)
		perm[i] = i;
	i = 0;
	while (i < dim - 1)
	{
		j = 0;
		while (j < dim - 1 - i)
		{
			if (arr[perm[j]] > arr[perm[j + 1]])
			{
				temp = perm[j];
				perm[j] = perm[j + 1];
				perm[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	put_index(t_stack *s)
{
	int		*perm;
	int		*arr;
	int		i;
	int		j;

	arr = malloc(((s->tail - s->head + s->size) % s->size) * sizeof(int));
	if (!arr)
		exit_error(s);
	i = 0;
	while ((s->head + i) % s->size != s->tail)
	{
		arr[i] = s->buffer[(s->head + i) % s->size];
		i++;
	}
	perm = malloc(((s->tail - s->head + s->size) % s->size) * sizeof(int));
	if (!perm)
	{
		free(arr);
		exit_error(s);
	}
	sort_arr(arr, ((s->tail - s->head + s->size) % s->size), perm);
	i = s->head;
	while (i != s->tail)
	{
		j = 0;
		while (j < (s->tail - s->head + s->size) % s->size)
		{
			if (s->buffer[i] == s->buffer[perm[j]])
				s->buffer[i] = j;
			j++;
		}
		i = (i + 1) % s->size;
	}
	printf("\n");
	i = s->head;
	while (i != s->tail)
	{
		printf("%d ", s->buffer[i]);
		i = (i + 1) % s->size;
	}
	free(perm);
	free(arr);
}
