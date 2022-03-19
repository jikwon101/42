NAME=ex02

SRCS=main.cpp Base.cpp A.cpp B.cpp C.cpp \
	 Generator.cpp Identify.cpp

OBJT=main.o Base.o A.o B.o C.o \
	 Generator.o Identify.o

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
