/* ex13.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
	key_t key;
	int msqid;

	printf("Enter the desired key in hex =");
	scanf("%x",&key);
	
	printf("\nkey=0x%x", key);
	if((msqid=msgget(key,IPC_CREAT|0660))==-1)
	{
		printf("The msgget failed.\n");
		exit(1);
	}
	printf("The msgget succeeded:msqid=%d \n",msqid);
	exit(0);
}
