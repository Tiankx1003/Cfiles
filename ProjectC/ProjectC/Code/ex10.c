#include  <stdio.h>
main()
{
	int i=1,result=1;
	while(i<=10)
	{
		result*=i;
		i++;
	}
	printf("10!=%d\n",result);
}
