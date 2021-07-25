# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 02:29:41 by jikwon            #+#    #+#              #
#    Updated: 2021/07/25 22:10:26 by jikwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pivot.a

SRCS=quickpivot.c quickpivot_utils.c 

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
