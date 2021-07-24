#include "log_utils.h"

void	remove_history(t_log *log)
{
	t_history	*target;

	if (!log || !log->last)
		return ;
	target = log->last;
	log->last = target->prev;
	if (log->last)
		log->last->next = NULL;
	free(target);
	return ;
}

int	isopposite(char *s1, char *s2)
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

void	add_firstlog(t_log *log, char *cmd)
{
	t_history	*newhistory;

	newhistory = (t_history *)malloc(sizeof(t_history));
	if (!newhistory)
		exit(1);
	newhistory->command = cmd;
	newhistory->next = NULL;
	newhistory->prev = NULL;
	log->last = newhistory;
}

t_history	*make_newhistory(char *cmd)
{
	t_history *res;

	if (!cmd)
		return (NULL);
	res = (t_history *)malloc(sizeof(t_history));
	if (!res)
		error("Malloc Error\n");
	res->command = cmd;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}
