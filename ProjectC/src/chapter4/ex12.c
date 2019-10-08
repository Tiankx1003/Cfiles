#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[])
{
	char buf[80];
	float radius, area;
	float pi=3.1419926;
	if(argc!=2)
	{
		printf("Usage: %s radius \n",argv[0]);
		return 1;
	}
	sscanf(argv[1],"%f",&radius);
	area=pi*radius*radius;
	sprintf(buf,"The area of a circle with radius %f is %f\n", radius, area);
	puts(buf);
	return 0;
}
