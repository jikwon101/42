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
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

// strcmp-> ft_strcmp 변경 필요:
static int		isopposite(char *s1, char *s2)
{	
	if ((!ft_strcmp(s1, "pa") && !ft_strcmp(s2, "pb")))
		return (1);
	if ((!ft_strcmp(s1, "pb") && !ft_strcmp(s2, "pa")))
		return (1);
	if ((!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rra")))
		return (1);
	if ((!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "ra")))
		return (1);
	if ((!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "rrb")))
		return (1);
	if ((!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rb")))
		return (1);
	if ((!ft_strcmp(s1, "sa") && !ft_strcmp(s2, "sa")))
		return (1);
	if ((!ft_strcmp(s1, "sb") && !ft_strcmp(s2, "sb")))
		return (1);
	if ((!ft_strcmp(s1, "ss") && !ft_strcmp(s2, "ss")))
		return (1);
	if ((!ft_strcmp(s1, "rr") && !ft_strcmp(s2, "rrr")))
		return (1);
	if ((!ft_strcmp(s1, "rrr") && !ft_strcmp(s2, "rr")))
		return (1);
	return (0);
}

// ft_strcmp-> ft_ft_strcmp 변경 필요:
int	ispair(char *s1, char *s2)
{
	if ((!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rb"))
		|| (!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "ra")))
		return (1);
	else if ((!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "rrb"))
		|| (!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rra")))
		return (2);
	else if ((!ft_strcmp(s1, "sa") && !ft_strcmp(s2, "sb"))
		|| (!ft_strcmp(s1, "sb") && !ft_strcmp(s2, "sa")))
		return (3);
	return (0);
}

static void	addlog(t_log *log, char *cmd)
{
	char		*lastcmd;
	t_history	*newhistory;
	int			pairtype;

	if (log->last == NULL)
	{	
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
	if (isopposite(lastcmd, cmd))
	{
		remove_history(log);
		return ;
	}
	pairtype = ispair(lastcmd, cmd);
	if (pairtype > 0)
	{
		remove_history(log);
		if (pairtype == 1)
			addlog(log, "rr");
		else if (pairtype == 2)
			addlog(log, "rrr");
		else if (pairtype == 3)
			addlog(log, "ss");
		return ;
	}
	newhistory = (t_history *)malloc(sizeof(t_history));
	if (!newhistory)
		exit(1);
	newhistory->command = cmd;
	newhistory->next = NULL;
	newhistory->prev = log->last;
	log->last->next = newhistory;
	log->last = newhistory;
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
