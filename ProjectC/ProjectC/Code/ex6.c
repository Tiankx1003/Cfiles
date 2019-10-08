#include "stdio.h"
main()
{
	float length,width,height;
	float area,volume;
	printf("Input length,width,height:\n");
	scanf("%f,%f,%f",&length,&width,&height);
	area=2*(length*width+length*height+width*height);	/*计算长方体表面积*/
	volume=length*width*height;							/*计算长方体体积*/
	printf("%f,%f,%f\n",length,width,height);
	printf("The surface area is %f, volume is %f\n",area,volume);
}
