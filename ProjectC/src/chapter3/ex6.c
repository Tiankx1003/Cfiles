#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define DUMMY 0
#define BUFSIZE 1024

char *validID[]={"123\n", "5678\n", "007\n", "421\n", "F"};

char str1[]={"1234"}, str2[]={"1234"};

int main(int argc, char *argv[])
{
	int fd, flags;
	int n;
	char userno[BUFSIZE], **ptr;
	ptr=validID;
	printf("%d \n",strcmp(str1,str2));
	setbuf(stdout,(char *) NULL);
	if((fd=open("/dev/tty", O_RDONLY | O_NDELAY))==-1)
	{
		printf("open error!\n");
		return 1;
	}
	printf("Enter your user ID :\n");
	sleep(3);
	if(read(fd, userno,BUFSIZE)==0)
	{
		printf("Bye Bye!\n");
		return 2;
	}
	while((strcmp(*ptr, userno)!=0)&&(strcmp(*ptr,"F")!=0))
		++ptr;
	if(strcmp(*ptr,"F")==0)
	{
		puts("Invalid user ID\n");
		return 3;
	} 
	flags=fcntl(fd, F_GETFL,DUMMY);
	flags&=fcntl(fd, F_SETFL,flags);
	printf("Enter your department Number:\n");
	n=read(fd, userno, BUFSIZE);
	printf("\n Welcome to Department #");
	write(1, userno, n);
	close(fd);
	return 0;
}


