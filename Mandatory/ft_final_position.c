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

static void	bubble_sort(int *arr, int dim)
{
	int	i;
	int	j;
	int	temp;
	int	swapped;

	i = 0;
	swapped = 1;
	while (i < dim - 1 && swapped)
	{
		swapped = 0;
		j = 0;
		while (j < dim - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}

static void	put_index(t_stack *s, int *arr)
{
	int		i;
	int		j;

	i = s->head;
	while (i != s->tail)
	{
		j = 0;
		while (j < (s->tail - s->head + s->size) % s->size)
		{
			if (s->buffer[i] == arr[j])
			{
				s->buffer[i] = j;
				break ;
			}
			j++;
		}
		i = (i + 1) % s->size;
	}
}

void	put_final_position(t_stack *s)
{
	int		*arr;
	int		i;

	arr = malloc(((s->tail - s->head + s->size) % s->size) * sizeof(int));
	if (!arr)
		exit_error(s, NULL);
	i = 0;
	while ((s->head + i) % s->size != s->tail)
	{
		arr[i] = s->buffer[(s->head + i) % s->size];
		i++;
	}
	bubble_sort(arr, i);
	put_index(s, arr);
	free(arr);
}
