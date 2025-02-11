/*ex2cli.c*/
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define	MAXBUFFSIZE	256
#define	PORT 6666
#define HOST_ADDR "127.0.0.1"
int main(int argc, char *argv[])
{
	int sockfd,n;
	char recvbuff[MAXBUFFSIZE];
	struct sockaddr_in	servaddr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("Socket created failed.\n");
		return -1;
	}	
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(6666);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	printf("connecting...\n");
	if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
	{
		printf("Connect server failed.\n");
		return -1;
	}	
	while((n=read(sockfd,recvbuff,MAXBUFFSIZE))>0)
	{
		recvbuff[n]=0;
		fputs(recvbuff,stdout);
	}
	if(n<0)
	{
		printf("Read failed!\n");
		return -2;
	}
	return 0;
}


