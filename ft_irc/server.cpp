#include <iostream>
#include <sys/socket.h> //socket
#include <netinet/in.h> //IPPORTO_TCP 
#include <sys/types.h> //sockaddr
#include <string.h> //memset
#include <arpa/inet.h> // inet_addr, hton
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/seletc.h>
#include <errno.hpp>

#define SA sockaddr

template <typename T>
void print(T src) { std::cout << src; }

int main()
{
	fd_set sockets;
	int server_sockfd, client_sockfd;
	struct sockaddr_in serveraddr, clientaddr;
	int res;
	unsigned int client = sizeof(clientaddr);
	int opt = 1;

	server_sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));	
	memset(&serveraddr, 0, sizeof(serveraddr));	
	serveraddr.sin_family = PF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);	
	serveraddr.sin_port = htons(8080);

	if (bind(server_sockfd, (SA *)(&serveraddr), sizeof(serveraddr)) == -1)
	{	print("Error in bind\n");  exit(1);}

	if (listen(server_sockfd, 5) < 0)
	{	print("Error in listen\n"); exit(1);}
	

	print("Server is waiting\n");
	while (1)
	{
		FD_SET(server_sockfd, &sockets);
		FD_SET( ???, &sockets);
		select();
		if (FD_ISSET(server_sockfd, fd_set))
		{
			client_sockfd = accept(server_sockfd, (SA *)(&clientaddr), &client);
			if (client_sockfd == -1)
				print("Error in accept\n");
			std::cout << client_sockfd << "is connected\n";
			print("client ip : "); 
			print(inet_ntoa(clientaddr.sin_addr)); print("\n");
		}
		for ()
		{
			if (FD_ISSET(s, fd_set))
				do_client_service(s);
		}
		if (send(set[i], buf, len, 0) != -1)
		{
			std::cout << "Error in send\n";
		}
	}
}
