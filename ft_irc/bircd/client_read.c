#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "bircd.h"
#include <string.h>
#include "../gnl/get_next_line.h"

int		check_msg(t_env *e, int cs, char *msg)
{
	return (1);
}

void	do_cmd(t_env *e, int cs, char *msg)
{
	int i;
	int temp;

	i = 0;
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) &&
			(i != cs))
		{
			temp = send(i, msg, strlen(msg), 0);
			printf("sent %dbytes to User %d\n", temp, i);
	   	}
		i++;
	}

}

void	client_read(t_env *e, int cs)
{
  int	r;
  //int	i;

  r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
  printf("recevie %d from User %d \n", r, cs);
  if (r <= 0)
  {
      close(cs);
      clean_fd(&e->fds[cs]);
      printf("client #%d gone away\n", cs);
  }
  else
  {
		  /*
	int i = 0;
	e->fds[cs].buf_read[r] = '\0';
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) &&
			(i != cs))
		{
			memcpy(e->fds[i].buf_write, e->fds[cs].buf_read, r);
			int temp = send(i, e->fds[i].buf_write, r, 0);
			printf("sent %dbytes to User %d\n", temp, i);
	   	}
		i++;
	}
	*/

	char *msg;
	e->fds[cs].request = ft_strjoin(e->fds[cs].request, e->fds[cs].buf_read);
	memset(e->fds[cs].buf_read, 0, BUF_SIZE +1);
	int res = get_next_msg(&(e->fds[cs].request), &msg);
	if (res)
	{
		if (check_msg(e, cs, msg))
			do_cmd(e, cs, msg);
	}
	char temp[] = "001\r\n";
	send(cs, temp, strlen(temp), 0);

   }
}
