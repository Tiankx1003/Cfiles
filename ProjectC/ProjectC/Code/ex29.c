#define  LENGTH 6
#include <stdio.h>
main()
{	
	char *pstr[]={"Beijing", "NewYork", "Paris", "London", "Washington", "Tokyo"};
	char **p;
	int i;
	for(i=0;i<LENGTH; i++)
	{
		p=pstr+i;
		printf("%s \n", *p);
	}
}

