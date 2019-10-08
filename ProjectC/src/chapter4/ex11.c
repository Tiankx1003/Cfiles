#include <stdio.h>
int main()
{
int i=23;
long int limt=1234567890;
char filename[]="file.txt";
printf("limt=%i \n limt=%li \n", limt,limt);
printf("Processing of '%s' is %d %% finished. Please be patient.\n",filename, i);
printf("%s \n",filename,i);
printf("%s is finished. %d %s \n",filename);

return 0;
}
