#include "utils.h"

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
