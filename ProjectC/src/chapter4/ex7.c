#include <stdio.h>
#include <stdlib.h>
char buf[132];

int main(int argc, char *argv[])
{
	FILE *fp;
	fpos_t pos;
	if(argc!=2)
	{
		printf("usage: %s mode \n",argv[0]);
		return 1;
	}
	if(argv[1][0]!='a')
	{
		if((fp=fopen("testfile","w+"))==NULL)
		{
			printf("fopen failed!\n");
			return 2;
		}
	}
	else
	{
		if((fp=fopen("testfile","a+"))==NULL)
		{
			printf("fopen failed!\n");
			return 3;
		}
	}
	fputs("1234567890",fp);
	fputs("abcdefghij",fp);
	fseek(fp,0,SEEK_END);
	fgetpos(fp,&pos);
	printf("current file end position is %ld \n",pos);
	fseek(fp,30,SEEK_END);
	fgetpos(fp,&pos);
	printf("call fseek(fp,30,SEEK_END)\n");
	printf("current file position is %ld \n",pos);
	fputs("abcdefg",fp);
	printf("write %c %s %c \n",'\"',"abcdfg",'\"');
	fgetpos(fp,&pos);
	printf("current position of file is %ld \n",pos);
	fclose(fp);											

}
