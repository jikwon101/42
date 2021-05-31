#include <iostream>
#include <sys/socket.h> //socket
#include <netinet/in.h> //IPPORTO_TCP 
#include <sys/types.h> //sockaddr
#include <string.h> //memset
#include <arpa/inet.h> // inet_addr, hton
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
template <typename T>
void	print(T arg)
{
	std::cout << arg <<std::endl;
}

int main()
{
	int server_sockfd, client_sockfd;
	struct sockaddr_in serveraddr, clientaddr;
	int pagefd, res;
	char buf_out[1024];
	char buf_in[1024];
	unsigned int client;
	int opt = 1;

	server_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);					//[1]
	setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));			//[2]
	print(server_sockfd);
	memset(&serveraddr, 0, sizeof(serveraddr));									//[3]
	serveraddr.sin_family = AF_INET;											//[4]
	//serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");						//[5]
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);								//[6]
	serveraddr.sin_port = htons(8080);

	if (bind(server_sockfd, (sockaddr *)(&serveraddr), sizeof(serveraddr)) == -1)	//[7]
	{	print("Error in bind\n"); exit(1); close(server_sockfd);}
	listen(server_sockfd, 5);													//[8]
	
	char header[] = "HTTP/1.1 200 OK\n"
			 "Date : Mon, 31 May 2021 12:34.56 GMT\n"
			 "Server: Apache/1.3.19 (Unix) PHP/4.0.6\n"
			 "X-Powered-By: PHP/4.0.6\n"
			 "Connection: close\n"
			 "Content-Type: text/html\n\n";										//[9]
	int cnt = 0;																//[10]
	while (1)
	{
		cnt++;
		client = sizeof(clientaddr);
		client_sockfd = accept(server_sockfd, (sockaddr *)(&clientaddr), &client);	//[11]
		if (client_sockfd == -1)
		{	print("Error in accept\n"); close(client_sockfd); break;}
	
		pagefd = open("./test.html", O_RDONLY);									//[12]
		memset(buf_in, 0x00, 1024);
		while ((res = read(client_sockfd, buf_in, 1024)) > 0)					//[13]
			break;
		write(client_sockfd, header, strlen(header));							//[14]
		while((res = read(pagefd, buf_out, 255)) > 0)							//[15]
		{
			write(client_sockfd, buf_out, res);
			memset(buf_out, 0x00, 255);
		}
		close(client_sockfd);
		close(pagefd);
		//if (cnt >= 8)
		//	break;
	}
	close(server_sockfd);
}
