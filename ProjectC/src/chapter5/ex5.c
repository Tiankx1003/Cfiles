#include <stdio.h>
#include <unistd.h>


int main()
{
	printf("===system call execl testing ===\n");
	execlp("date","date",0);
	printf("exec error !\n");
	
	return 0;
}
