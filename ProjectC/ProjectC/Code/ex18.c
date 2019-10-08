#include <stdio.h>
main( )
{
	int f( );
	int j;
for (j=1; j<=3; j++)
	printf ("%d\n",f( ));
}
int f( ) 
{
	static int i=0;
	i++;
	return i;
}
