/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:49:39 by sdell-er          #+#    #+#             */
/*   Updated: 2024/03/12 18:21:31 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../my_lib/Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*buffer;
	int		size;
	int		head;
	int		tail;
	char	name;
}	t_stack;

typedef struct s_lst
{
	void			*value;
	struct s_lst	*next;
}	t_lst;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_lst	*op_a;
	t_lst	*op_b;
	int		expanded;
}	t_data;

void	swap(t_stack *s);
void	push(t_stack *s1, t_stack *s2);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);

int		is_digit(char *str);
int		is_int(long int n);
int		is_sorted(t_stack *s, int ord);
void	exit_error(t_data *ab);

void	sort_3(t_data *ab);
void	sort_5(t_data *ab);
void	sort_n(t_data *ab);

int		sorted_pos(t_stack *s, int n, t_data *ab);
int		dist_top(t_stack *s, int i, int *d_tail);
int		s_len(t_stack *s);
void	i_at_top(t_stack *a, int i);

void	swap_s(t_stack *s);
void	push_s(t_stack *s1, t_stack *s2);
void	rotate_s(t_stack *s);
void	reverse_rotate_s(t_stack *s);

void	swap_ab(t_stack *a, t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);
void	reverse_rotate_ab(t_stack *a, t_stack *b);

void	put_final_position(t_stack *s, t_data *ab);
void	insert_last(t_lst **list, void *value);
int		total_moves_if(t_stack *a, t_stack *b, int min_moves, int choice);
int		better_pb_init(t_data *ab);
int		moves_number(t_stack *a, t_stack *b, int link);
int		put_next(t_stack *a, t_stack *b, int link, int choice);
int		index_n(t_stack *s, int value);

#endif