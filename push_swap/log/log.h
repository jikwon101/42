#ifndef LOG_H
# define LOG_H

# include "log_utils.h"

# define INIT 0
# define ADD 1
# define PRINT 2
# define CLEAR 3
# define NOCMD NULL

void	control_log(int option, char *cmd);

#endif
