#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char * argv[])
{
	int fd;
	if(argc<2)
	{
		printf("useage dup2  filename.\n");
		return 1;	
	}
	if((fd=open(argv[1],O_WRONLY|O_CREAT,0644))==-1)
	{	
		printf("Open file %s errof!\n",argv[1]);
		return 2;
	}
	if(dup2(fd, STDOUT_FILENO)==-1)
	{
		printf("dup2 fd failed!\n");
		return 3;
	}
	printf("dup2()  call successed!\n");
	close(fd);
	return 0;
}
