#include <stdio.h>
main()
{
	float a[2][3],b[2]; 		/*内部数组不能初始化*/
	int i;
	char c[20]="12345";
	char str1[100]="Beijing",str2[]="China";
	strcat(str1,str2);
	puts(str1);
	/* 给数组赋值*/
	a[0][0]=15.2; a[0][1]=13.2;a[0][2]=10.6;
	a[1][0]=6.7; a[1][1]=2.3; a[1][2]=13.3;
	printf("%d\n",strlen(c));
	for(i=0;i<2;i++)
	{
		b[i]=a[i][0]+a[i][1]+a[i][2];
		printf("%f %f %f %f\n",a[i][0],a[i][1],a[i][2],b[i]);
	}

}



