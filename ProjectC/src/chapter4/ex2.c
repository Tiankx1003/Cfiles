#include <stdio.h>
int main(int argc, char *argv[])
{
	FILE	*fp1, *fp2;
	if((fp1=fopen("file1.txt","w"))==NULL)
	{	
		printf("Open file1.txt failed!\n");
		return 1;
	}
	if((fopen("file2.txt","w"))==NULL)
	{
		printf("Open  file2.txt failed!\n");
		return 2;
	}
	if(fcloseall()==EOF)
		{
			printf("close fil1.txt file2.txt failed!\n");
			return 3;
		}
	else
		printf("streams closed successfully!\n");
	return 0;
}
