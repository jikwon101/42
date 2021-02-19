#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	0
#define TYPE_PIPE	1
#define TYPE_BREAK	2

typedef struct	s_list
{
	char			**args;
	int				length;
	int				type;
	int				pipes[2];
	struct s_list	*previous;
	struct s_list	*next;
}				t_list;

int ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int show_error(char const *str)
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

void *exit_fatal_ptr(void)			//exit_fatal 과 같은 기능인데 이 함수를 반환하는 함수의 반환형 때문에 ptr만듦
{
	exit_fatal();
	exit(EXIT_FAILURE);
	return (NULL);
}

char *ft_strdup(char const *str)
{
	char	*copy;
	int		i;

	if (!(copy = (char*)malloc(sizeof(*copy) * (ft_strlen(str) + 1))))
		return (exit_fatal_ptr());
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

int add_arg(t_list *cmd, char *arg)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!(tmp = (char**)malloc(sizeof(*tmp) * (cmd->length + 2))))		//일단 tmp에 문자열 두 줄 넣을 수 있는 만큼 할당
		return (exit_fatal());
	while (i < cmd->length)												//tmp 에 그 전에 있던 argument들 가져와서 넣고
	{
		tmp[i] = cmd->args[i];
		i++;
	}
	if (cmd->length > 0)												// 구버전은 free해버림.
		free(cmd->args);
	cmd->args = tmp;													// length가 0이면 바로 여기로 와서 args[0]에 문자열 arg 저장
	cmd->args[i++] = ft_strdup(arg);									// 새로운 argument 추가
	cmd->args[i] = 0;
	cmd->length++;
	return (EXIT_SUCCESS);
}

int list_push(t_list **list, char *arg)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(*new))))		// 일단 구조체 하나를 할당하고, 멤버들을 초기화해줌.
		return (exit_fatal());
	new->args = NULL;
	new->length = 0;
	new->type = TYPE_END;
	new->previous = NULL;
	new->next = NULL;
	if (*list)										// 현재 구조체가 첫번째 멤버라면, *list는 NULL 일테니 조건 만족 안함
	{												// 현재 구조체가 두번째 멤버라면, *list의 next와 현재 구조체를 연결
		(*list)->next = new;
		new->previous = *list;
	}
	*list = new;									// 현재 구조체 위치를 new로 다시 설정.
	return (add_arg(new, arg));						// 구조체 내 멤버변수 값 설정.
}

int list_rewind(t_list **list)
{
	while (*list && (*list)->previous)				// 연결리스트의 처음 위치로 돌아간다.
		*list = (*list)->previous;
	return (EXIT_SUCCESS);
}

int parse_arg(t_list **cmds, char *arg)
{
	int	is_break;

	is_break = (strcmp(";", arg) == 0);		// 인자가 ";" 인지 검사
	if (is_break && !*cmds)					// 인자가 ; 이고 cmds 가 NULL이면 return 0 (그냥 ;로 시작하는 경우 아무것도 안하고 넘어간다)
		return (EXIT_SUCCESS);
	else if (!is_break && (!*cmds || (*cmds)->type > TYPE_END))		// 인자가 ";"이 아니면서 (cmds가 NULL이거나 type이 TYPE_END보다 크면)
		return (list_push(cmds, arg));								// list_push 함수로 cmd리스트에 추가
	else if (strcmp("|", arg) == 0)			// 인자가 "|" 이면
		(*cmds)->type = TYPE_PIPE;			// type 을 TYPE_PIPE로  (TYPE_PIPE = 1)
	else if (is_break)						// 인자가 ";" 이기만 하면 
		(*cmds)->type = TYPE_BREAK;			// type 을 TYPE_BREAK로 (TYPE_BREAK = 2)
	else
		return (add_arg(*cmds, arg));		// 그 외, 예를들어 path같은 경우. add_arg로 구조체의 args 변수에 저장됨.
	return (EXIT_SUCCESS);
}

int exec_cmds(t_list **cmds, char **env)
{
	t_list	*crt;							//current
	int		ret;

	ret = EXIT_SUCCESS;
	list_rewind(cmds);
	while (*cmds)
	{
		crt = *cmds;
		if (strcmp("cd", crt->args[0]) == 0)
		{
			ret = EXIT_SUCCESS;
			if (crt->length < 2)
				ret = show_error("error: cd: bad arguments\n");
			else if (chdir(crt->args[1]))		//chdir() 성공시 0 리턴, 실패시 -1 리턴
			{
				ret = show_error("error: cd: cannot change directory to ");
				show_error(crt->args[1]);
				show_error("\n");
			}
		}
		else
			ret = exec_cmd(crt, env);
		if (!(*cmds)->next)						//연결리스트의 끝에 도달하면 탈출
			break ;
		*cmds = (*cmds)->next;
	}
	return (ret);
}

#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	t_list	*cmds;
	int		i;
	int		ret;

	int		j;

	ret = EXIT_SUCCESS;
	cmds = NULL;
	i = 1;
	while (i < argc)						//argv 인자를 처음부터 끝까지 하나씩 파싱함수에 넘김
	{
		parse_arg(&cmds, argv[i]);
		i++;
	}
	if (cmds)
		ret = exec_cmds(&cmds, env);
	list_rewind(&cmds);

	while (cmds != NULL){					// 파싱 잘 됐나 확인해보기
		j = 0;
		while (cmds->args[j])
		{
    		printf("cmds->args[%d] = %s\n", j, cmds->args[j]);
			j++;
		}
		printf("cmds->type : %d\n\n", cmds->type);
    	cmds = cmds->next;
	}
	
	return (ret);
}
