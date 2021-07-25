# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 02:30:23 by jikwon            #+#    #+#              #
#    Updated: 2021/07/25 02:30:24 by jikwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=sort.a

SRCS=sort.c \
	a_sort.c a_sort_utils.c a_sort_check.c \
	d_sort.c d_sort_utils.c d_sort_check.c

OBJT=$(SRCS:.c=.o)

CFLAG=-Wall -Wextra -Werror -g3

all : $(NAME)

$(NAME) : $(SRCS)
	gcc $(CFLAG) -c $(SRCS)
	ar rc $(NAME) $(OBJT)
	ranlib $(NAME)

clean : 
	rm -rf $(OBJT)
	
fclean : clean
	rm -rf $(NAME)

re : fclean all
