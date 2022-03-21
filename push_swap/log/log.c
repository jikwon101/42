/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:28:54 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/25 02:28:55 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

static void	initlog(t_log *log)
{
	log->last = NULL;
}

static void	addlog(t_log *log, char *cmd)
{
	char		*lastcmd;
	t_history	*newhistory;
	int			pairtype;

	if (log->last == NULL)
		return (add_firstlog(log, cmd));
	lastcmd = log->last->command;
	if (isopposite(lastcmd, cmd))
		return (remove_history(log));
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
	newhistory = make_newhistory(cmd);
	newhistory->prev = log->last;
	log->last->next = newhistory;
	log->last = newhistory;
}

static void	clearlog(t_log *log)
{
	t_history	*pos;

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

static void	printlog(t_log *log)
{
	t_history	*pos;

	if (!log || !log->last)
		return ;
	pos = log->last;
	while (pos->prev)
		pos = pos->prev;
	while (pos)
	{
		write(1, pos->command, ft_strlen(pos->command));
		write(1, "\n", 1);
		pos = pos->next;
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
	return ;
}
