#include <stdio.h>

int main()
{
	int c, answer;
	printf("1: This is a buffer test program.\n");
	 fflush(NULL) ;
	fprintf(stderr,"2: Ihope this should be second line.\n");
	printf("3: Hello, Are you a student?");
	while(1) 
	{
		c=tolower(fgetc(stdin));
		answer=c;
		while(c !='\n'&&c!=EOF)
			c=fgetc(stdin);
		if(answer=='y')
		{
			printf("Hope you have good score.");
			break;
		}
		else if(answer=='n')
		{
			printf("Hope you have good salary.\n");
			break;
		}
		else
			printf("Please answer y or n: ");
	}
	fflush(NULL);
	fprintf(stderr,"n-1: I hope this line should last but one.\n");
	printf("\nn: Test over .\n");
	return 0;
}
