#include "libft.h"

void	errorexit(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
