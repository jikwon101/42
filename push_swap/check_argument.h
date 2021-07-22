#ifndef CHECK_ARGUMENT_H
# define CHECK_ARGUMENT_H

#include "libft.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h> //temp

int	is_int(char *str);
int	is_under_min(char *str, int len);
int is_over_max(char *str, int len);
int	isn_int_range(char *str);
int	is_duplicate(int *data, int size, int n);
int check_arguments(int **data, int size, char *argv[]);

#endif
