#include <stdio.h>
struct record{
	int uid;
	char login[10];
};

char *logins[]={"user1","user2","user3","user4","user5"};

void putrec(FILE *fp, int i, struct record *ps)
{
	fseek(fp,(long)i*sizeof(struct record),0);
	fwrite((char *)ps,sizeof(struct record),1,fp);
}

int main(int argc, char *argv[])
{
	int i;
	FILE *fp;
	struct record rec;
	if(argc<=1)
	{
		printf("usage: %s datafile \n",argv[0]);
		return 1;
	}
	if((fp=fopen(argv[1],"w"))==NULL)
	{
		printf("Create  file %s failed!", argv[1]);
		return 2;
	}
	for(i=4;i>=0;i--)
	{
		rec.uid=i;
		strcpy(rec.login,logins[i]);
		putrec(fp,i,&rec);
	}
	fclose(fp);
	return 0;
}
