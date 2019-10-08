#include <stdio.h>
main()
{
	int i,sum,score[10];	
	float average;
	sum=0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&score[i]);
		sum+=score[i];
	}
	average=(float)sum/10;
	printf("Average=%f\n",average);
}
