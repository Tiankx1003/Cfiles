/* ex7.c */
#include <stdio.h>
#include <signal.h>

void inthandler(int signum);
void continuehandler(int signum);
void terminatehandler(int signum);

int main()
{
	char buffer[100];
	if(signal(SIGINT,&inthandler)==-1)
	{
		printf("Couldn't register signal hanlder for SIGINT!\n");
		exit(1);
	}	
	if(signal(SIGTSTP, &inthandler)==-1)
	{
		printf("Couldn't register signal hanlder for SIGTSTP!\n");
		exit(2);
	}
	if(signal(SIGCONT, &continuehandler)==-1)
	{
		printf("Couldn't register signal hanlder for SIGCONT!\n");
		exit(3);
	}
	if(signal(SIGTERM, &terminatehandler)==-1)
	{
		printf("Couldn't register signal hanlder for SIGINT!\n");
		exit(4);
	}
	printf("Pid of This Process : %d \n",getpid());
	
	for(;;)
	{
		printf("Please input:\n");
		fgets(buffer, sizeof(buffer),stdin);
		if(strcmp(buffer,"int\n")==0)
			raise(SIGINT);
		else if(strcmp(buffer,"stop\n")==0)
			raise(SIGTSTP);
		else if(strcmp(buffer,"continue\n")==0)
			raise(SIGCONT);
		else if(strcmp(buffer,"quit\n")==0)
			raise(SIGTERM);
		else
			printf("Your input is: %s \n",buffer);
	}
	exit(0);
}

void inthandler(int signum)
{
	printf("catch signal %d \n",signum);
}

void continuehandler(int signum)
{
	printf("Continue code.\n");
}

void terminatehandler(int signum)
{
	printf("signal SIGTERM \n");
	exit(0);
}
