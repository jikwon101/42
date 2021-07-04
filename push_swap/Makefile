SRCS=main.c push_swap.c quickpivot.c stack.c
LIB=libft.a
OBJT= $(SRCS:.c=.o)
NAME=a.out
CFLAG=-g3
all : $(NAME)

$(NAME) :
	gcc $(CFLAG) $(SRCS) $(LIB) -o $(NAME) 

clean : 
	rm -f $(OBJT)
	
fclean : clean
	rm -rf $(NAME)

re : fclena all
