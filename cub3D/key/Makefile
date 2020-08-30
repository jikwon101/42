NAME = keycontrol.a
SRCS = main.c move.c
CFLG = -g3 -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS) keycontrol.h
	gcc $(CFLG) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
	
re : fclean all
