#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	char buf[6];
	fd=open("./test.c",0);
	read(fd,buf,6);
	printf("====output in main()= ===\n%s\n",buf);
	fcntl(fd, F_SETFD,1);
	execl("./test","./test",0);
	printf("exec error \n");
}
