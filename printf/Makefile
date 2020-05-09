NAME=libftprintf.a
SRCS=ft_printf.c ft_printf_conversion.c ft_printf_init.c ft_printf_utils.c
OBJECTS=$(SRCS:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) ft_printf.h
	make -C libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o : %.c
	${CC} ${CFLAGS} -I. -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
