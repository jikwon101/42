SRCS = main.c init.c free.c
CFLG = -g3 -Wall -Werror -Wextra -lmlx -L./
READ_FILE = ./read_file/read_file.a
LIBFT = ./libft/libft.a
KEYCONTROL = ./key/keycontrol.a
DRAW = ./draw/draw.a
FILE = ./map.cub
NAME = cub3D

all : $(NAME)

$(NAME) : $(READ_FILE) $(LIBFT) $(KEYCONTROL) $(DRAW)
	gcc -o $(NAME) $(SRCS) $(READ_FILE) $(LIBFT) $(KEYCONTROL) $(DRAW) $(CFLG)

$(READ_FILE) :
	$(MAKE) -s -C ./read_file
	$(MAKE) clean -C ./read_file

$(LIBFT) : 
	$(MAKE) -s -C ./libft
	$(MAKE) clean -C ./libft

$(KEYCONTROL) : 
	$(MAKE) -s -C ./key
	$(MAKE) clean -s -C ./key
	
$(DRAW) : 
	$(MAKE) -s -C ./draw
	$(MAKE) clean -s -C ./draw

clean:
	rm -rf $(SRCS:.c=.o)
	rm -rf $(READ_FILE) $(LIBFT) $(KEYCONTROL) $(DRAW)

fclean: clean
	rm -rf $(NAME)
	rm -rf cub3D.dSYM

re : fclean all
