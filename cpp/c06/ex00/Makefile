NAME=ex00

SRCS=Conversion.cpp main.cpp

OBJT=$(SRCS:.c=.o)

FLAG=-Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME): $(OBJT)
	clang++ $(FLAG) $(OBJT) -o $(NAME)

$(OBJT): $(SRCS)
	clang++ $(FLAG) -c $(SRCS)
	
clarn:
	rm -rf $(OBJT)

fclean:
	rm -rf $(NAME)

re: fclean all
