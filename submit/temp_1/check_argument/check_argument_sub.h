#ifndef CHECK_ARGUMENT_SUB_H
# define CHECK_ARGUMENT_SUB_H

# include "../include/libft.h"

int	is_int(char *str);
int	is_under_min(char *str, int len);
int	is_over_max(char *str, int len);
int	isn_int_range(char *str);
int	is_duplicate(int *data, int size, int n);

#endif
