#include <iostream>
#include <sys/socket.h> //socket
#include <netinet/in.h> //IPPORTO_TCP 
#include <sys/types.h> //sockaddr
#include <string.h> //memset
#include <arpa/inet.h> // inet_addr, hton
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <thread>

#define SA sockaddr

template <typename T>
void print(T src) { std::cout << src; }

void funt(int fd)
{	
	int client_sockfd = fd;
	int len = 100;
	char rbuf[len];
	int res = 0;

	while (1)
	{
		if ((res = recv(client_sockfd, rbuf, len, 0)) == -1)
		{ print("Error in recv\n");	}
		else if (res > 0)
		{
			rbuf[res] = '\0';
			std::cout << rbuf << "\n";
		}
	}
}

int main(int ac, char *av[])
{

	int server_sockfd, client_sockfd;
	struct sockaddr_in serveraddr, clientaddr;
	int res;
	unsigned int server = sizeof(serveraddr);

	/* Create socket */
	client_sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	memset(&clientaddr, 0, sizeof(clientaddr));	
	serveraddr.sin_family = PF_INET;
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");	
	serveraddr.sin_port = htons(80);
	

	if (connect(client_sockfd, (SA *)(&serveraddr),server) < 0)
	{ print("Error in connect\n"); exit(1);}

	std::thread _t1(funt, client_sockfd);
	int len = 100;
	//char sbuf[len];
	std::string sbuf;
	while (1)
	{
		getline(std::cin, sbuf);
		if ((res = send(client_sockfd, sbuf.c_str(), len, 0)) == -1)
			print("Error in send\n");
	}
	close(client_sockfd);
	exit(0);
}
