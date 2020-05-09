# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikwon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 22:16:54 by jikwon            #+#    #+#              #
#    Updated: 2020/02/14 03:32:58 by jikwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./srcs/
FILES = ft_putchar.c ft_putstr.c ft_strcmp.c \
		ft_strlen.c ft_swap.c
OBJECTS = ft_putchar.o ft_putstr.o ft_strcmp.o \
		  ft_strlen.o ft_swap.o
HEADERS = includes/

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRCS)$(FILES)  -o $(SRCS)
	ar rc libft.a $(SRCS)$(OBJECTS)
	ranlib libft.a

clean:
	/bin/rm -f $(SRCS)$(OBJECTS)

fclean: clean
	/bin/rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re
