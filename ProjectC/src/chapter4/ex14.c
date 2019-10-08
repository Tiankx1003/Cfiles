#include <stdio.h>
int main()
{
	FILE *tempfp;
	char line[256];
	tempfp=tmpfile();
	if(tempfp==NULL)
	{
		printf("tmpfile error!\n");
		return 1;
	}
	printf("Opened a temporary file OK!\n");
	fputs("One line of output \n",tempfp);
	rewind(tempfp);
	if(fgets(line, sizeof(line),tempfp)==NULL)
	{
		printf("fgets error!\n");
		return 2;
	}
	fputs(line, stdout);
	return 0;
}
