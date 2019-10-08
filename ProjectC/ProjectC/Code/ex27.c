#include <stdio.h>
main()
{
	char *strcon(char ch);
	char *ps, s='A';
	ps=strcon(s);
	printf("%s \n",ps);
}

char *strcon(char ch)
{
	static char sa[10];
	int i;
	for(i=0;i<6; i++)
	sa[i]=ch-i;
	sa[6]='\0';
	return(sa);
}
