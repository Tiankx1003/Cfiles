#include <stdio.h>
struct complex{
	float real,image;
};
main()
{
	static struct complex x={1.0,2.0},y={3.0,4.0};
	struct complex z1,z2,add(),multiply();
	z1=add(&x,&y);
	z2=multiply(&x,&y);
	printf("(%f+i%f)+(%f+i%f)=",x.real,x.image,y.real,y.image);
	printf("%f+i%f\n",z1.real,z1.image);
	printf("(%f+i%f)*(%f+i%f)=",x.real,x.image,y.real,y.image);
	printf("%f+i%f\n",z2.real,z2.image);
}
struct complex add(struct complex *px,struct complex *py)
{
	struct complex z;
	z.real=px->real+py->real;
	z.image=px->image+py->image;
	return z;
}
struct complex multiply(struct complex *px,struct complex *py)
{
	struct complex z;
	z.real=px->real*py->real-px->image*py->image;
	z.image=px->real*py->image+px->image*py->real;
	return z;
}
	
