/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:49:39 by sdell-er          #+#    #+#             */
/*   Updated: 2024/01/24 11:50:10 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../my_lib/Libft/libft.h"
# include "../my_lib/get_next_line/get_next_line_bonus.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*buffer;
	int	size;
	int	head;
	int	tail;
	int	expanded;
}	t_stack;

void	swap(t_stack *s);
void	push(t_stack *s1, t_stack *s2);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);

int		is_digit(char *str);
int		is_present(t_stack *s, int value);
int		is_int(long int n);
int		is_sorted(t_stack *s);
void	exit_error(t_stack *s);

void	execute(t_stack *a, t_stack *b, char **op);
void	free_if(char ***argv, t_stack *a);

#endif