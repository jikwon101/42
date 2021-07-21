#include "log.h"

static void	initlog(t_log *log)
{
	log->last = NULL;
}

static void	remove_history(t_log *log)
{
	t_history *target;

	if (!log || !log->last)
		return ;
	target = log->last;
	log->last = target->prev;
	if (log->last)
		log->last->next = NULL;
	free(target);
	return ;
}

static int		strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

static int		isopposite(char *s1, char *s2)
{	
	if ((strcmp(s1, "pa") && strcmp(s2, "pb")))
		return (1);
	if ((strcmp(s1, "pb") && strcmp(s2, "pa")))
		return (1);
	if ((strcmp(s1, "ra") && strcmp(s2, "rra")))
		return (1);
	if ((strcmp(s1, "rra") && strcmp(s2, "ra")))
		return (1);
	if ((strcmp(s1, "rb") && strcmp(s2, "rrb")))
		return (1);
	if ((strcmp(s1, "rrb") && strcmp(s2, "rb")))
		return (1);
	if ((strcmp(s1, "sa") && strcmp(s2, "sa")))
		return (1);
	if ((strcmp(s1, "sb") && strcmp(s2, "sb")))
		return (1);
	return (0);
	if ((strcmp(s1, "pa") && strcmp(s2, "pb"))
		|| (strcmp(s1, "pb") && strcmp(s2, "pa"))
		|| (strcmp(s1, "ra") && strcmp(s2, "rra"))
		|| (strcmp(s1, "rra") && strcmp(s2, "ra"))
		|| (strcmp(s1, "rb") && strcmp(s2, "rrb"))
		|| (strcmp(s1, "rrb") && strcmp(s2, "rb"))
		|| (strcmp(s1, "sa") && strcmp(s2, "sa"))
		|| (strcmp(s1, "sb") && strcmp(s2, "sb")))
			return (1);
	return (0);
}

static void	addlog(t_log *log, char *cmd)
{
	char	*lastcmd;
	t_history	*newhistory;

	//printf("%s\n", cmd);
	if (log->last == NULL)
	{	
		//printf("%s\n", cmd);
		newhistory = (t_history *)malloc(sizeof(t_history));
		if (!newhistory)
			exit(1);
		newhistory->command = cmd;
		newhistory->next = NULL;
		newhistory->prev = NULL;
		log->last = newhistory;
		return ;
	}
	lastcmd = log->last->command;
	if (!isopposite(lastcmd, cmd))
	{
		//printf("%s\n", cmd);
		newhistory = (t_history *)malloc(sizeof(t_history));
		if (!newhistory)
			exit(1);
		newhistory->command = cmd;
		newhistory->next = NULL;
		newhistory->prev = log->last;
		log->last->next = newhistory;
		log->last = newhistory;
	}
	else
	{
		remove_history(log);
	}
}

static void	printlog(t_log *log)
{
	t_history *pos;

	if (!log || !log->last)
		return ;
	pos = log->last;
	while (pos->prev)
		pos = pos->prev;
	while (pos)
	{
		printf("%s\n", pos->command);
		pos = pos->next;
	}
	return ;
	//pos = log->last;
	//if (pos->prev)
	//	printlog(remove_history(log));
	//printf("%s\n", pos->command);
	//free(pos);
}

static void	clearlog(t_log *log)
{
	t_history *pos;

	if (!log)
		return ;
	pos = log->last;
	while (pos)
	{
		remove_history(log);
		pos = log->last;
	}
	return ;
}

void	control_log(int option, char *cmd)
{
	static t_log	log;

	if (option == INIT)
		initlog(&log);
	else if (option == ADD)
		addlog(&log, cmd);
	else if (option == PRINT)
		printlog(&log);
	else if (option == CLEAR)
		clearlog(&log);
}
