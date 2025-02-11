/*ex6.c*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#define  LISTENQ 	5


int listenfd, connfd;
void sig_urg(int signo);
int main()
{
	int n;
	char buff[100];
	socklen_t	len;
	struct sockaddr_in	servaddr, cliaddr;
	struct sigaction action;
	action.sa_handler=sig_urg;
	sigemptyset(&action.sa_mask);
	action.sa_flags=0;
	listenfd=socket(AF_INET, SOCK_STREAM,0);
	if(listenfd<0)
	{
		printf("Socket created failed.\n");
		return -1;
	}
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(6666);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr))<0)
	{
		printf("bind failed.\n");
		return -1;
	}
	printf("listening....\n");
	listen(listenfd, LISTENQ);
	len=sizeof(cliaddr);
	connfd=accept(listenfd,(struct sockaddr *)&cliaddr, &len);
	if(sigaction(SIGURG,&action, NULL)==-1)
	{
		printf("Couldn't register signal handler.\n");
		return -2;
	}
	fcntl(connfd,F_SETOWN,getpid());
	while(1)
		{
		 if((n=read(connfd,buff,sizeof(buff)))==0)
			{
				printf("received EOF \n");
				return 0;
			}
		buff[n]=0;
		printf("read %d bytes: %s \n",n,buff);
	}
}

void sig_urg(int signo)
{
	int n;
	char buff[100];
	printf("SIGURG received \n");
	n=recv(connfd,buff,sizeof(buff),MSG_OOB);
	buff[n]=0;
	printf("read %d OOB byte: %s\n",n,buff);
}
