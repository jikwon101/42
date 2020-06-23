CF = -lmlx -lXext -lX11 -lbsd
MEM = -g3 -fsanitize=address
lib = ./libft_bonus/libft.a
fi = ./srcs/info.cub
all : 
	gcc new.c -lmlx -lXext -lX11 -lbsd
	./a.out
check : 
	gcc main.c $(lib) $(CF)
	./a.out $(fi)
img : 
	gcc images.c libft.a $(CF) $(MEM)
	./a.out
clean :
	rm a.out
