#include <stdio.h>
main()
{
	int a=1;
	printf("a1=%d\n",a);
	fadd(a);
	printf("a4=%d\n",a);
}

fadd(int n)
{
	printf("a2=%d\n",n);
	n+=3;
	printf("a3=%d\n",n);
}
