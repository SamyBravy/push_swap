# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 19:17:18 by sdell-er          #+#    #+#              #
#    Updated: 2024/03/12 17:44:43 by sdell-er         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
MY_LIB = ./my_lib
LIB = ./my_lib/my_lib.a
SRC = ./Mandatory/push_swap.c ./Mandatory/check_ft.c ./Mandatory/operations.c ./Mandatory/sort_ft.c ./Mandatory/sort_utils.c ./Mandatory/commands_s.c ./Mandatory/commands_ab.c ./Mandatory/sort_n_utils.c
SRC_B = ./Bonus/checker_bonus.c ./Bonus/check_ft_bonus.c ./Bonus/operations_bonus.c ./Bonus/execute_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
FLAGS = -g -Wall -Wextra -Werror
CC = cc

all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJ)
	@make -C $(MY_LIB) > /dev/null
	@$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME) > /dev/null
	@echo "\e[0;93m[$(NAME)] compiled!\e[0m"
	
$(NAME_BONUS) : $(OBJ_B)
	@make -C $(MY_LIB) > /dev/null
	@$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_BONUS) > /dev/null
	@echo "\e[0;93m[$(NAME_BONUS)] compiled!\e[0m"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C $(MY_LIB) > /dev/null
	@rm -f $(OBJ) $(OBJ_B)
	@echo "\e[0;91mcleaned!\e[0m"

fclean: clean
	@make fclean -C $(MY_LIB) > /dev/null
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "\e[0;91m[$(NAME)] deleted!\e[0m"
	@echo "\e[0;91m[$(NAME_BONUS)] deleted!\e[0m"

re: fclean all

reboth : fclean all bonus

rebonus : fclean bonus

.PHONY: all clean fclean re
