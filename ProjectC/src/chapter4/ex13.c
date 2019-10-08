#include <stdio.h>

int main(void)
{
	char tmpname[L_tmpnam];
	char *filename;
	FILE *fp;
	char *pfx="xxx";
	printf("Temporary file name1 is %s\n",tmpnam(NULL));
	tmpnam(tmpname);
	printf("Temporary file name2 is %s\n",tmpname);
	if((fp=fopen(tmpname,"w"))==NULL)
	{
		printf("fopen failed\n");
		return 1;
	}
	else
		printf("write tempfile %s ok \n", tmpname);
	printf("%s \n", tempnam("/tmp/lxy",pfx));
	printf("%s \n",tempnam(NULL," "));
	printf("%s \n",tempnam("tmp/lxy",pfx));
	return 0;
}
