#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int rfd, wfd;
char c;

int main(int argc, char*argv[])
{
	if(argc!=3)
	{
		printf("Usage %s sourcesfiel destfile. \n",argv[0]);
		return 1;
	}
	if((rfd=open(argv[1], O_RDONLY))==-1)
	{
		printf("openf file %s failed.\n",argv[1]);
		return 2;
	}
	if((wfd=creat(argv[2],0666))==-1)
	{
		printf("create file %s failed.\n",argv[2]);
		return 3;
	}
	fork();
	for(;;)
	{
		if(read(rfd,&c,1)!=1)
			return 4;
		write(wfd,&c,1);
	}
	return 0;
}

