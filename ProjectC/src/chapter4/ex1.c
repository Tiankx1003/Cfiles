#include <stdio.h>
int main(int argc, char *argv[])
{
	FILE	*fp;
	int		iflag;
	if(argc<=1)
	{
		printf("usage: %s filename\n",argv[0]);
		return 1;
	}
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("Open  file %s failed!", argv[1]);
		return 2;
	}
	printf("Open file %s successfully!\n",argv[1]);
	iflag=fclose(fp);
	if(iflag==0)
		{
			printf("Close file %s successfully!\n",argv[1]);
			return 0;
		}
	else
		{
			printf("Close file %s failed! ", argv[1]);
			return 3;
		}
} 
