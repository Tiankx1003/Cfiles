#include <stdio.h>
main()
{
	int a[3],i=0;
	int *pa;
	a[0]=1;a[1]=2;a[2]=5;
	for(pa=a;pa<a+3;pa++)
	printf("a[%d]=%d\n",i++,*pa);

}
