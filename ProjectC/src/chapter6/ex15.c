/* ex15.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg
{
	long int my_msg_type;
	char text[BUFSIZ];
} msgbuf;

int main()
{
	int running =1;
	int msgid;
	msgid=msgget((key_t)1234,0666 |IPC_CREAT);
	if(msgid==-1)
	{
		printf("msgget failed!\n");
		exit(1);
	}
	while(running)
	{
		printf("Enter some text: ");
		fgets(msgbuf.text,BUFSIZ,stdin);
		msgbuf.my_msg_type=1;	
		if(msgsnd(msgid,(void *)&msgbuf, BUFSIZ, 0)==-1)
		{
			printf("msgsnd failed!\n");
			exit(1);
		}
		if(strncmp(msgbuf.text,"end",3)==0)
			running=0;
	}
	return 0;
}
