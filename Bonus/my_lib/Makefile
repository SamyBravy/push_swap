# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 15:44:24 by sdell-er          #+#    #+#              #
#    Updated: 2024/01/18 21:01:51 by sdell-er         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_lib.a
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

SRCS = ./Libft/ft_isascii.c ./Libft/ft_memcpy.c ./Libft/ft_putstr_fd.c ./Libft/ft_strlcat.c ./Libft/ft_strrchr.c \
	./Libft/ft_atoi.c ./Libft/ft_isdigit.c ./Libft/ft_memmove.c ./Libft/ft_split.c ./Libft/ft_strlcpy.c \
	./Libft/ft_strtrim.c ./Libft/ft_bzero.c ./Libft/ft_isprint.c ./Libft/ft_memset.c ./Libft/ft_strchr.c \
	./Libft/ft_strlen.c ./Libft/ft_substr.c ./Libft/ft_calloc.c ./Libft/ft_itoa.c ./Libft/ft_putchar_fd.c \
	./Libft/ft_strdup.c ./Libft/ft_strmapi.c ./Libft/ft_tolower.c ./Libft/ft_isalnum.c ./Libft/ft_memchr.c \
	./Libft/ft_putendl_fd.c ./Libft/ft_striteri.c ./Libft/ft_strncmp.c ./Libft/ft_toupper.c ./Libft/ft_isalpha.c \
	./Libft/ft_memcmp.c ./Libft/ft_putnbr_fd.c ./Libft/ft_strjoin.c ./Libft/ft_strnstr.c ./Libft/ft_lstdelone.c \
	./Libft/ft_lstclear.c ./Libft/ft_lstsize.c ./Libft/ft_lstlast.c ./Libft/ft_lstnew.c ./Libft/ft_strcmp.c \
	./Libft/ft_lstiter.c ./Libft/ft_lstadd_back.c ./Libft/ft_lstadd_front.c ./Libft/ft_lstmap.c \
	./ft_printf/ft_printf.c ./ft_printf/ft_putchar.c ./ft_printf/ft_putstr.c ./ft_printf/ft_putnbr.c ./ft_printf/ft_putexa.c \
	./get_next_line/get_next_line_bonus.c ./get_next_line/get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c my_lib.h
	@$(CC) $(CC_FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
