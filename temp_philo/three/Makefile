NAME=philo_three

SRCS=main.c \
	 clean.c \
	 utils.c \
	 init.c \
	 monitor.c

OBJT=$(SRCS:.c=.o)

FLAG=-Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJT)
	gcc $(FLAG) $(OBJT) -o $(NAME)

$(OBJT): $(SRCS)
	gcc $(FLAG) -c $(SRCS)

clean:
	rm -rf $(OBJT)

fclean: clean
	rm -rf $(NAME)

re: fclean all
