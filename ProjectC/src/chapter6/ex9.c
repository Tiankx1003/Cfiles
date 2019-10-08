/* ex9.c */
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
	int n, fd[2];
	pid_t pid;
	char buffer[BUFSIZ+1];
	if(pipe(fd)<0)
	{
		printf("pipe failed!\n ");
		exit(1);
	}
	if((pid=fork())<0)
	{
		printf("fork failed!\n ");
		exit(1);
	}
	else if (pid>0)
	{
		close(fd[0]);
		write(fd[1],"How are you?\n",12);
	}
	else
	{
		close(fd[1]);
		n=read(fd[0],buffer,BUFSIZ);
		write(STDOUT_FILENO,buffer,n);
	}
	exit(0);
}
