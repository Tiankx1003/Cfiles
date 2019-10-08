#include <stdio.h>
int get_line(char *buf, int bufsize, FILE *fp)
{
	if(fgets(buf,bufsize,fp)==NULL)
	{	
		if(feof(fp))
		{
			printf("End of file \n");
			return EOF;
		}
		else
		{
			printf("fgets failed\n");
			return 0;
		}
	}
	printf("call fgets: %s ", buf);
	return 1;
}

char buf[132];
int main(int argc, char *argv[])
{
	FILE *fp;
	if(argc<=1)
	{
		printf("usage: %s file \n",argv[0]);
		return 1;
	}
	if((fp=fopen(argv[1],"w+"))==NULL)
	{
		printf("fopen failed!\n");
		return 2;
	}
	fprintf(fp, "This is firlst line.\n");
	fprintf(fp, "This is seconf line. \n");
	fclose(fp);
	if((fp=fopen(argv[1],"r+"))==NULL)
	{
		printf("fopen failed!\n");
		return 3;
	}
	get_line(buf,sizeof(buf),fp);
	/* fflush(fp); */
	fprintf(fp, "This line should be the new second line.\n");
	
	fflush(fp); 
	get_line(buf,sizeof(buf),fp);
	fclose(fp);
	return 0;
}
