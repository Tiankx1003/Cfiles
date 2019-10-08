#include <stdio.h>
int plus(int x, int y)
{
	return (x+y);
}
main()
{
	int a=5, b=3, c,d;
	int (*func)();
	func=plus;
	c=(*func)(a,b);
	d=plus(a,b);
	printf("%d+%d=%d\n",a,b,c);
	printf("%d+%d=%d\n",a,b,d);
}
