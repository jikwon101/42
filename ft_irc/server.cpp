#include <iostream>
#include <sys/socket.h> //socket
#include <netinet/in.h> //IPPORTO_TCP 
#include <sys/types.h> //sockaddr
#include <string.h> //memset
#include <arpa/inet.h> // inet_addr, hton
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define SA sockaddr

template <typename T>
void print(T src) { std::cout << src; }

int main()
{
	int server_sockfd, client_sockfd;
	struct sockaddr_in serveraddr, clientaddr;
	int res;
	unsigned int client = sizeof(clientaddr);
	int opt = 1;

	/* Create socket */
	server_sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	/* Set socket option */
	setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));	
	memset(&serveraddr, 0, sizeof(serveraddr));	
	serveraddr.sin_family = PF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);	
	serveraddr.sin_port = htons(8080);

	/* Binding */
	if (bind(server_sockfd, (SA *)(&serveraddr), sizeof(serveraddr)) == -1)
	{	print("Error in bind\n");  exit(1);}

	/* Listenging */
	if (listen(server_sockfd, 5) < 0)
	{	print("Error in listen\n"); exit(1);}

	int buffersize = 1024;
	char msg[buffersize];
	int msgsize;
	int set[10];
	int cnt = 0;
	print("Server is waiting\n");
	while (1)
	{

	client_sockfd = accept(server_sockfd, (SA *)(&clientaddr), &client);
	if (client_sockfd == -1)
	{	print("Error in accept\n"); }
	else
		cnt++;
	std::cout << client_sockfd << "is connected\n";
	set[cnt-1] = client_sockfd;
	print("Server is connected\n");
	print("client ip : "); print(inet_ntoa(clientaddr.sin_addr)); print("\n");
	char buf[] = "Connect is alive\n";
	int len = strlen(buf);
	for (int i = 0; i < cnt ; i++)
	{
		std::cout << set[i] << "trynig\n";
		if (send(set[i], buf, len, 0) != -1)
		{
			std::cout << "Error in send\n";
		}
	}
	}
	//close(client_sockfd);
	//close(server_sockfd);
}
