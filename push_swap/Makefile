NAME=push_swap

CC=gcc

CFLAG= -g3 -Wall -Werror -Wextra

SRCS=main.c quickpivot.c

OBJT=$(SRCS:.c=.o)

LIB=./libft/libft.a

CHECK_ARG=./check_argument/check_argument.a

LOG=./log/log.a

STACK=./stack/stack.a

COMMAND=./command/command.a


all : $(NAME)

$(NAME) : $(LIB) $(CHECK_ARG) $(LOG) $(STACK) $(COMMAND)
	$(CC) -o $(NAME) $(SRCS) $(LIB) $(CHECK_ARG) $(LOG) $(STACK) $(COMMAND)

$(LIB) :
	$(MAKE) -s -C ./libft
	$(MAKE) clean -C ./libft

$(CHECK_ARG) : 
	$(MAKE) -s -C ./check_argument
	$(MAKE) clean -C ./check_argument

$(LOG) : 
	$(MAKE) -s -C ./log
	$(MAKE) clean -C ./log

$(STACK) : 
	$(MAKE) -s -C ./stack
	$(MAKE) clean -C ./stack

$(COMMAND) : 
	$(MAKE) -s -C ./command
	$(MAKE) clean -C ./command

clean : 
	rm -rf $(OBJT)
	rm -rf $(LIB) $(CHECK_ARG) $(LOG) $(STACK) $(COMMAND)
	
fclean : clean
	rm -rf $(NAME)

re : fclean all
