# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 02:27:32 by jikwon            #+#    #+#              #
#    Updated: 2021/07/25 02:27:33 by jikwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	 ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	 ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	 ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
	 ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c ft_strcmp_bonus.c ft_strtrim.c \
	 ft_errorexit.c 

OBJT=$(SRCS:.c=.o)

INCLUDES=./

CC=gcc

CFLAGS=-Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(SRCS) libft.h
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OBJT)
	ranlib $(NAME)

clean:
	rm -rf $(OBJT)

fclean: clean
	rm -rf $(NAME)

re: fclean all
