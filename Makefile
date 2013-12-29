#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/27 19:34:26 by gpetrov           #+#    #+#              #
#    Updated: 2013/12/29 21:13:53 by gpetrov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= push_swap
SRCS	= main.c ft_p.c ft_r.c ft_sort.c funct.c
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
