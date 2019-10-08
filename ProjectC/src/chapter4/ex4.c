#include <stdio.h>
int main(int argc , char *argv[])
{
	char buf[1024];
	FILE	*fp;
	if((fp=fopen("file1.txt", "r"))==NULL)
	{	
		printf("File open error. \n");
		return 1;
	}
	while((fgets(buf,1024,fp))!=0)
		puts(buf);
	return 0;
}

