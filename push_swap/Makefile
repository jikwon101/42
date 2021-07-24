SRCS=main.c quickpivot.c stack_mani.c log.c check_argument_main.c utils.c check_argument_sub.c log_utils.c stack_utils.c stack_print.c stack_else.c command_sp.c command_r.c command_rr.c
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
