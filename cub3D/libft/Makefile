NAME = libft.a
SRCS = ft_atoi.c ft_isdigit.c ft_memcpy.c ft_split.c ft_strchr.c ft_strcmp_bonus.c \
	   ft_strdup.c ft_strjoin.c ft_strlen.c ft_strtrim.c get_next_line_bonus.c \
	   ft_memset.c ft_strchr.c
OBJS =  $(SRCS:.c=.o)
CFLG = -Wall -Wextra -Werror
BUFF = -D BUFFER_SIZE=10

all : $(NAME)

$(NAME) :
	gcc $(CFLG) -c $(SRCS) $(BUFF)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
