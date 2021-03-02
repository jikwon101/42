#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# define SIDE_OUT 0
# define SIDE_IN 1

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define TYPE_END 0
# define TYPE_PIPE 1
# define TYPE_BREAK 2

typedef struct s_list
{
	char  **args;
	int length;
	int type;
	int pipe[2];
	struct s_list *prev;
	struct s_list *next;
}	t_list;

int ft_strlen(const char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}
int show_error(const char *str)
{
	if (str)
		write(STDERR, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

int exit_fatal(void)
{
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void *exit_fatal_ptr(void)
{
	exit_fatal();
	exit(EXIT_FAILURE);
	return (NULL);
}

char *ft_strdup(const char *str)
{
	int i;
	char *result;

	i = 0;
	result = (char *)malloc(ft_strlen(str) + 1);
	if (result == NULL)
		return (exit_fatal_ptr());
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int add_arg(t_list *cmd, char *arg)
{
	char **tmp;
	int i;

	i = 0;
	tmp = NULL;
	tmp = (char **)malloc(sizeof(char *) * (cmd->length + 2));
	if (!tmp)
		return (exit_fatal());
	while (i < cmd->length)
	{
		tmp[i] = cmd->args[i];
		i++;
	}
	if (cmd->length > 0)
		free(cmd->args);
	cmd->args = tmp;
	(cmd->args)[i++] = ft_strdup(arg);
	cmd->args[i] = 0;
	cmd->length++;
	return (EXIT_SUCCESS);
}

int list_add_end(t_list **list, char *arg)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (exit_fatal());
	new->args = NULL;
	new->length = 0;
	new->type = TYPE_END;
	new->prev = NULL;
	new->next = NULL;
	if (*list)
	{
		(*list)->next = new;
		new->prev = *list;
	}
	*list = new;
	return (add_arg(new, arg));

}

int list_rewind(t_list **list)
{
	if (!*list)
		return (EXIT_FAILURE);
	while ((*list)->prev)
		*list = (*list)->prev;
	return (EXIT_SUCCESS);
}

int list_clear(t_list **cmd)
{
	t_list *tmp;
	int i;

	list_rewind(cmd);
	while (*cmd)
	{
		tmp = (*cmd)->next;
		i = 0;
		while (i < (*cmd)->length)
			free((*cmd)->args[i++]);
		free((*cmd)->args);
		free(*cmd);
		(*cmd) = tmp;
	}
	*cmd = NULL;
	return (EXIT_SUCCESS);
}

int	parse(t_list **cmd, char *arg)
{
	int is_break;

	is_break = (strcmp(";", arg) == 0);
	if (is_break && *cmd == NULL)
		return (EXIT_SUCCESS);
	else if (!is_break && (*cmd == NULL || (*cmd)->type > TYPE_END))
		return (list_add_end(cmd, arg));
	else if (strcmp("|", arg) == 0)
		(*cmd)->type = TYPE_PIPE;
	else if (is_break)
		(*cmd)->type = TYPE_BREAK;
	else
		return (add_arg(*cmd, arg));
	return (EXIT_SUCCESS);
}

int exec_cmd(t_list *cmd, char **env)
{
	pid_t pid;
	int ret;
	int status;
	int pipe_open;

	ret = EXIT_FAILURE;
	pipe_open = 0;
	if (cmd->type == TYPE_PIPE ||
					(cmd->prev && cmd->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(cmd->pipe))
			return (exit_fatal());
	}
	pid = fork();
	if (pid < 0)
		return (exit_fatal());
	else if (pid == 0)
	{
		if (cmd->type == TYPE_PIPE
				&& dup2(cmd->pipe[SIDE_IN], STDOUT) < 0)
			return (exit_fatal());
		if (cmd->prev && cmd->prev->type == TYPE_PIPE
				&& dup2(cmd->prev->pipe[SIDE_OUT], STDIN) < 0)
			return (exit_fatal());
		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0)
		{
			show_error("error: cannot execute");
			show_error(cmd->args[0]);
			show_error("\n");
		}
		exit(ret);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->pipe[SIDE_IN]);
			if (!cmd->next || cmd->type == TYPE_BREAK)
				close(cmd->pipe[SIDE_OUT]);
		}
		if (cmd->prev && cmd->prev->type ==TYPE_PIPE)
			close(cmd->prev->pipe[SIDE_OUT]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}
int exec(t_list **cmd, char **env)
{
	t_list *tmp;
	int ret;

	ret =  EXIT_SUCCESS;
	list_rewind(cmd);
	while (*cmd)
	{
		tmp = *cmd;
		if (strcmp("cd", tmp->args[0]) == 0)
		{
			if (tmp->length < 2)
				ret = show_error("erro: cd: bad arguments\n");
			else if (chdir(tmp->args[1]))
			{
				ret = show_error("error: cd: cannot chang directory to");
				show_error(tmp->args[1]);
				show_error("\n");
			}
		}
		else
			ret = exec_cmd(tmp, env);
		if (!(*cmd)->next)
			break ;
		*cmd = (*cmd)->next;
	}
	return (ret);
}

int main(int ac, char **av, char **env)
{
	t_list *cmd;
	int	i;
	int	ret;
	
	ret = EXIT_SUCCESS;
	cmd = NULL;
	i = 1;
	while (i < ac)
		parse(&cmd, av[i++]);
	if (cmd)
		ret = exec(&cmd, env);
	list_clear(&cmd);
	return (ret);
}
