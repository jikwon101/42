SRCS=main.c quickpivot.c stack_mani.c log.c check_argument_main.c utils.c check_argument_sub.c log_utils.c stack_utils.c stack_print.c stack_else.c command_sp.c command_r.c command_rr.c

P_CHECK_ARG=./check_argument/
P_COMMAND=./command/
P_LOG=./log/
P_STACK=./stack/
P_UTILS=./utils/

S_CHECK_ARG=$(P_CHECK_ARG)/check_argument.c $(P_CHECK_ARG)/check_argument_sub.c
S_COMMAND=$(P_COMMAND)/command_sp.c $(P_COMMAND)/command_r.c $(P_COMMAND)/command_rr.c
S_LOG=$(P_LOG)/log.c $(P_LOG)/log_utils.c
S_STACK=$(P_STACK)/stack_mani.c $(P_STACK)/stack_else.c $(P_STACK)/stack_utils.c $(P_STACK)/stack_print.c
S_UTILS=$(P_UTILS)/utils.c

O_CHECK_ARG=$(S_CHECK_ARG:.c=.o)
O_COMMAND=$(S_COMMAND:.c=.o)
O_LOG=$(S_LOG:.c=.o)
O_STACK=$(S_STACK:.c=.o)
O_UTILS=$(S_UTILS:.c=.o)

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
