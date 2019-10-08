#include <stdio.h>
main()
{
	int a=9, b=5, c=-17;
	printf("a&b=%d, a&c=%d, b&c=%d \n",a&b,a&c,b&c);
	printf("a|b=%d, a|c=%d, b|c=%d \n",a|b,a|c,b|c);
	printf("a^b=%d, a^c=%d, b^c=%d\n",a^b,a^c,b^c);
	printf("~a=%d, ~b=%d, ~c=%d\n",~a,~b,~c);
	printf("a<<4=%d, b<<4=%d, c<<4=%d\n",a<<4,b<<4,c<<4);
	printf("a>>4=%d, b>>4=%d, c>>4=%d\n",a>>4,b>>4,c>>4);
}
