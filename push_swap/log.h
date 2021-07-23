#ifndef LOG_H
# define LOG_H

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define INIT 0
# define ADD 1
# define PRINT 2
# define CLEAR 3
# define NOCMD NULL

typedef struct s_history
{
	char	*command;
	struct	s_history	*next;
	struct	s_history	*prev;
}				t_history;

typedef struct s_log
{
	t_history *last;
}				t_log;

void	control_log(int option, char *cmd);
#endif
