# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 02:31:56 by jikwon            #+#    #+#              #
#    Updated: 2021/07/26 01:38:51 by jikwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CC=gcc

CFLAG= -g3  #-Wall -Werror -Wextra

SRCS=main.c pivot/quickpivot.c sort/sort.c

OBJT=$(SRCS:.c=.o)

LIB=./libft/libft.a

CHECK_ARG=./check_argument/check_argument.a

LOG=./log/log.a

STACK=./stack/stack.a

COMMAND=./command/command.a

SORT=./sort/sort.a

PIVOT=./pivot/pivot.a

all : $(NAME)

$(NAME) : $(LIB) $(CHECK_ARG) $(LOG) $(STACK) $(COMMAND) $(SORT) $(PIVOT)
	$(CC) $(CFLAG) -o $(NAME) $(SRCS) $(LIB) $(CHECK_ARG) $(LOG) $(STACK) $(COMMAND) $(SORT) $(PIVOT)

$(LIB) :
	$(MAKE) -s -C ./libft
	$(MAKE) clean -C ./libft

$(CHECK_ARG) : 
	$(MAKE) -s -C ./check_argument
	$(MAKE) clean -C ./check_argument

$(LOG) : 
	$(MAKE) -s -C ./log
	$(MAKE) clean -C ./log

$(STACK) : 
	$(MAKE) -s -C ./stack
	$(MAKE) clean -C ./stack

$(COMMAND) : 
	$(MAKE) -s -C ./command
	$(MAKE) clean -C ./command

$(SORT) : 
	$(MAKE) -s -C ./sort
	$(MAKE) clean -C ./sort

$(PIVOT) : 
	$(MAKE) -s -C ./pivot
	$(MAKE) clean -C ./pivot


clean : 
	rm -rf $(OBJT)
	rm -rf $(LIB) $(CHECK_ARG) $(LOG) $(STACK) $(COMMAND) $(SORT) $(PIVOT)
	
fclean : clean
	rm -rf $(NAME)

re : fclean all
