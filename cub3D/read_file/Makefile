NAME = read_file.a
SRCS = main.c set_elem.c check_map.c utils_elem.c utils_map.c free.c
OBJS = $(SRCS:.c=.o)
CFLG = -g3 -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS) read_file.h
	gcc $(CFLG) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJS)
	
fclean : clean
	rm -rf $(NAME)

re : fclean all
