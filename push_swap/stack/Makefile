NAME=stack.a
SRCS=stack_else.c stack_mani.c stack_utils.c stack_print.c
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
