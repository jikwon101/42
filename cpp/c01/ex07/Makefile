NAME=replace
SRCS=main.cpp sed.cpp
OBJT=$(SRCS:.cpp=.o)
FLAG=-Wall -Werror -Wextra -std=c++98 -g3

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
