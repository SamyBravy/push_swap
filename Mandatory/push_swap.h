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
	char	name;
	int		*buffer;
	int		size;
	int		head;
	int		tail;
	int		expanded;
}	t_stack;

typedef struct s_lst
{
	void			*value;
	struct s_lst	*next;
}	t_lst;

void	init(t_stack *s, int size, char name, t_stack *s_tofree);

void	swap(t_stack *s);
void	push(t_stack *s1, t_stack *s2);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);

int		is_digit(char *str);
int		is_present(t_stack *s, int value);
int		is_int(long int n);
int		is_sorted(t_stack *s, int ord);
void	exit_error(t_stack *s1, t_stack *s2);

void	sort_3(t_stack *a, t_stack *b);
void	sort_5(t_stack *a);
void	sort_n(t_stack *a);

int		sorted_pos(t_stack *s, int n, t_stack *s_to_free);
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

void	put_final_position(t_stack *s);
int		total_moves_if(t_stack *a, t_stack *b, int min_moves, int choice);
int		better_pb_init(t_stack *a, t_stack *b);
int		moves_number(t_stack *a, t_stack *b, int link);
int		put_next(t_stack *a, t_stack *b, int link, int choice);

void	insert_last(t_lst **list, void *value);
void	free_list(t_lst **list);

#endif