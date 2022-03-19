NAME=phonebook
SRCS=main.cpp phonebook.cpp contact.cpp
OBJT=$(SRCS:.cpp=.o)
FLAG=-Wall -Werror -Wextra -std=c++98

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
