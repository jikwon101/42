NAME=ex00
SRCS1=main.cpp
SRCS2=main.cpp Extra.cpp
FLAG=-Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : 
	clang++ $(FLAG) -o $(NAME) $(SRCS1)

extra: fclean
	clang++ $(FLAG) -o $(NAME) $(SRCS2) -D TEST

clean:
	rm -rf $(SRCS:.c=.c)

fclean: clean
	rm -rf $(NAME)
	
re : fclean all
