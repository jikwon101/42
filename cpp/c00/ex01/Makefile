SRCS=main.cpp phonebook.cpp contact.cpp
OBJT=$(SRCS:.cpp=.o)
NAME=phonebook
FLAG=-Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJT)
	g++ $(FLAG) $(OBJT) -c $(NAME)

$(OBJT): $(SRCS)
	g++ $(FLAG) -c $(SRCS)

clean:
	rm -rf $(OBJT)

fclean: clean
	rm -rf $(NAME)

re: fclean all
