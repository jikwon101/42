NAME=get_next_line.a

SRCS=get_next_line.c get_next_line_utils.c
OBJT=get_next_line.o get_next_line_utils.o
INCLUDES=./
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS) get_next_line.h
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $(SRCS) -D BUFFER_SIZE=30
	ar rc $(NAME) $(OBJT)
	ranlib $(NAME)
	rm -rf $(SRCS:.c=.o)

clean:
	rm -rf $(SRCS:.c=.o)

fclean: clean
	rm -rf $(NAME)

test : 
	rm -rf printdiff
	$(CC) $(SRCS) main.c -D BUFFER_SIZE=1  -o printdiff
	cp printdiff ../


re: fclean all
