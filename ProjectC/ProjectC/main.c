#include "source1.h"
#include <stdio.h>
#include "max.c"

int jinzhi()
{
	int a = 3;
	printf("十进制是%d\n八进制是%o\n十六进制是%x\n", a, a, a);
	printf("前缀十进制是%#d\n前缀八进制是%#o\n前缀十六进制是%#x\n大写前缀十六进制%#X\n", a, a, a, a);
	return 0;
}



int main()
{
	Hello();
	max();
	jinzhi();
	return 0;
}

