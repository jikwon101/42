
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "bircd.h"
#include <string.h>
void	client_read(t_env *e, int cs)
{
  int	r;
  int	i;
  int temp;

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
      i = 0;
      while (i < e->maxfd)
	  {
		char buf[1024] = {0,};
		char num = cs + '0';
		strcat(buf, "User ");
		strcat(buf, &num);
		strcat(buf, " : ");
		strcat(buf, e->fds[cs].buf_read);
		r += 9;
	 	 if ((e->fds[i].type == FD_CLIENT) &&
	  			 (i != cs))
	  	{
			temp = send(i, buf, r, 0);
			//temp = send(i, e->fds[cs].buf_read, r, 0);
			printf("sent %dbytes to User %d\n", temp, i);
		}
		  i++;
		}
    }
}
