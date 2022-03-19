NAME=ex01

SRCS=main.cpp Data.cpp

OBJT=main.o Data.o

FLAG=-Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME): $(OBJT)
	clang++ $(FLAG) $(OBJT) -o $(NAME)

$(OBJT): $(SRCS)
	clang++ $(FLAG) -c $(SRCS)
	
clean:
	rm -rf $(OBJT)

fclean: clean
	rm -rf $(NAME)

re: fclean all
