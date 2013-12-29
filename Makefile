#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmp <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/29 02:30:43 by gmp               #+#    #+#              #
#    Updated: 2013/12/29 02:30:45 by gmp              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= push_swap
SRCS	= main.c
OBJS	= ${SRCS:.c=.o}
INC		= ./
FLAGS	= -Wall -Wextra -Werror -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	gcc $(FLAGS) $(SRCS) -o $(NAME) -I libft/includes -L libft/ -lft
%.o: %.c
	gcc -c $< -o $@ $(FLAGS) -I$(INC)
gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) -I libft/includes -L libft/ -lft
	gdb $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
