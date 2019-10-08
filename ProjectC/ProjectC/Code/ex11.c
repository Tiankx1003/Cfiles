#include <stdio.h>
main()
{	
	int i=1;
	float sum=0;
	do{
		sum+=1.0/i;
		i++;
	}	
	while(i<=1000);
	printf("1+1/2+...+1/1000= %f\n",sum);
}
