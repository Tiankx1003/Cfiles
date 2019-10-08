#include <stdio.h>
void swap(int *px, int *py)
{
	int x;
	x=*px;
	*px=*py;
	*py=x;
}

main()
{
	int i,a[10]={0,1,2,3,4,-5,6,-7,8,-9};
	int *p1, *p2;
	printf("The original array:\n");
	for(i=0;i<10;i++)
		printf("%d  ",a[i]);
	printf("\n");
	for(i=0;i<5;i++)
	{
		p1=&a[i];
		p2=&a[10-1-i];
		swap(p1,p2);
	}
	printf("The inverted array:\n");
	for(i=0;i<10;i++)
		printf("%d  ",a[i]);
	printf("\n");
}
