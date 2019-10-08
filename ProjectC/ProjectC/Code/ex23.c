#include <stdio.h>
main()
{
	char s[]="string";
	int i;
	for(i=0;s[i];i++)
		printf("%c",s[i]);
	printf("\n");
	printf("%s\n",s);
}
