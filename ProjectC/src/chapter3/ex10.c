#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
	int link_value, fd;
	const char *path="linkfile";
	struct stat orig_buf, new_buf;
	if(argc!=2)
	{
		printf("Usage a <pathname>\n");
		return 1;	
	}
	printf("create newfile\n");	
	if((fd=creat(argv[1]), S_IRWXU | S_IRWXG | S_IRWXO)==-1)
	{
		printf("create file  %s failed\n", argv[1]);
		return 2;
	}	
	printf("Get newfile status \n");
	stat(argv[1], &orig_buf);
	printf("orig_buf.st_nlink=%d \n", orig_buf.st_nlink);
	printf("create link from %s to %s \n", argv[1],path);
	if(link(argv[1],path));
	{
		printf("link call failed\n");
		//return 3;	
	}
	printf("link call successful \n");
	stat(argv[1],&new_buf);
	printf("new_buf.st_nlink=%d\n",new_buf.st_nlink);
	return 0;	
}
