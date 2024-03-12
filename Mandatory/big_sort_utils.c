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
	int		i;
	int		j;


	for (int i = 0; i < ((s->tail - s->head + s->size) % s->size); i++) {
		printf("%d ", s->buffer[i]);}
	perm = malloc(((s->tail - s->head + s->size) % s->size) * sizeof(int));
	sort_arr(s->buffer, ((s->tail - s->head + s->size) % s->size), perm);
	i = 0;
	while (i < ((s->tail - s->head + s->size) % s->size))
	{
		j = 0;
		while (j < ((s->tail - s->head + s->size) % s->size))
		{
			if (s->buffer[i] == s->buffer[perm[j]])
				s->buffer[i] = j;
			j++;
		}
		i++;
	}
	for (int i = 0; i < ((s->tail - s->head + s->size) % s->size); i++) {
		printf("%d ", s->buffer[i]);
	}
	free(perm);
}
