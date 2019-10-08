#include <stdio.h>
union  un_a{
	int		i;
	float	f;
	double	d;
	long  int	li;
} x;
main()
{
	x.i=6;
	printf("%d\n",x.i);
	x.d=3576266;
	printf("%f\n",x.d);
	x.f=2343.3434;
	printf("%f \n",x.f);
	x.li=3423499;
	printf("%d \n",x.li);
}
