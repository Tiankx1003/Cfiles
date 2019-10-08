#include "stdio.h"
main()
{
	char str[20];
	struct student{
	char	name[20];
	int		no;
	char 	gender[6];
	int 	age;
	float	score;
	} var;
	strcpy(var.name,"王小明"); /*为结构中的字符串成员赋值,注意，不能写成var.name=" 王小明"*/
	var.no=0314;			/*为结构中的整型成员赋值*/
	strcpy(var.gender,"男");	/*为结构中的字符串成员赋值*/
	var.age=15;				/*为结构中的整型成员赋值*/
	var.score=95.5;			/*为结构中的浮点型成员赋值*/
	printf("char: %d \t",sizeof(char));
	printf("int:  %d\t",sizeof(int));
	printf("long: %d\t",sizeof(long));
	printf("float: %d\t",sizeof(float));
	printf("double: %d\t",sizeof(double));
	printf("str: %d\t",sizeof(str));
	printf("student: %d\t",sizeof(struct student));
	printf("var: %d\t\n",sizeof(var));
}
