SRCS=main.c push_swap.c quickpivot.c stack.c log.c
LIB=libft.a		#folder libft 만들어서 새로 make 해서 컴파일해야함. 
OBJT= $(SRCS:.c=.o)
NAME=push_swap
CFLAG= -g3 -Wall -Werror -Wextra  #-fsanitize=address
all : $(NAME)

$(NAME) :
	gcc $(CFLAG) $(SRCS) $(LIB) -o $(NAME) 

clean : 
	rm -f $(OBJT)
	
fclean : clean
	rm -rf $(NAME)

re : fclean all
