NAME = draw.a
SRCS = draw_map.c draw_sprite.c utils.c saveimage.c
OBJS = $(SRCS:.c=.o)
CFLG = -Wall -Werror -Wextra -g3

all : $(NAME)

$(NAME) : $(SRCS)
	gcc $(CFLG) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
	
re : fclean all
