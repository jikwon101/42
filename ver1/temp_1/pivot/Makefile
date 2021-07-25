NAME=pivot.a

SRCS=quickpivot.c quickpivot_utils.c \
	 quickpivot_print.c #temp

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
