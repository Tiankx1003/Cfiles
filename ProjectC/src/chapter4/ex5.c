#include <stdio.h>

#define NAMESIZE 30

struct {
char name[NAMESIZE];
long number;
short department;
short scores[10];
} student;

short *pscores;

int main(int argc, char *argv[])
{
	FILE	*fpstudents;
	FILE	*fpscore;

	if(argc<=2)
	{
		printf("usage: %s sourcefile destfile\n",argv[0]);
		return 1;
	}
	if((fpstudents=fopen(argv[1],"r"))==NULL)
	{
		printf("Open  sourcefile %s failed!", argv[1]);
		return 2;
	}
	if((fpscore=fopen(argv[2],"w"))==NULL)
	{
		printf("Create  destfile %s failed!", argv[2]);
		return 3;
	}	
	while(fread(&student,sizeof(student),1,fpstudents)==1)
	{
		pscores=student.scores;
		if(fwrite(&pscores,sizeof(short),3,fpscore)!=3)
		printf("Error in writing file.\n");
		return 4;
	}
	return 0;	
}
