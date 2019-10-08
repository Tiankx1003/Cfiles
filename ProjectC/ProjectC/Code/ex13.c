#include  <stdio.h>
void main()
{
	int i;
	for(i=6;i<=100;i++)
	{
	if (i%6!=0)
	continue;
	printf("%d ",i);
	}
	printf("\n");
}
