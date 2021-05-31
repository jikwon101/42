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

#define SA sockaddr

template <typename T>
void print(T src) { std::cout << src; }

int main()
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
	serveraddr.sin_port = htons(8080);

	if (connect(client_sockfd, (SA *)(&serveraddr),server) < 0)
	{ print("Error in connect\n"); exit(1);}

	char buf[1024];
	int len = 1024;
	while (1)
	{
		if ((res = recv(client_sockfd, buf, len, 0)) == -1)
		{ print("Error\n");	}
		if (res)
			std::cout << buf << std::endl;
	}	
	close(client_sockfd);
	exit(0);
}
