#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	char path[1000];
	char file[1000];
	if(argc!=2)
	{
		printf("Usage mk <pathname>\n");
		return 1;
	}
	getwd(path);
	printf("current directory is :%s \n",path);
	if(mkdir(argv[1],S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH)<0)
	{
		printf("mkdir failed \n");
		return 2;
	}
	if(chdir(argv[1])<0)
	{
		printf("chdir failed \n");
		return 3;
	}
	getwd(path);
	printf("mkdir successed.\n New current directory is: %s\n",path);
	//rmdir(path);
	//printf("%s is removed\n",path);
	return 0;
}
