/* ex21 server.c*/
#include   "myshm.h"
int main()
{
	char *shm, *s;
	int shmid;
	int producer, consumer,i;
	char readbuf[SHMSZ];
	consumer=open_semaphore_set(ftok("consumer",0),1);
	init_a_semaphore(consumer,0,1);
	producer=open_semaphore_set(ftok("producer",0),1);
	init_a_semaphore(producer,0,1);

	if((shmid=shmget(ftok("shared",0),SHMSZ, 0666|IPC_CREAT))==-1)
	{	
		printf("shmget failed.\n");
		exit(1);
	}
	if((shm=shmat(shmid,(unsigned char *)0,0))==-1)
	{	
		printf("shmat failed.\n");
		exit(1);
	}
	for(i=0; ; i++)
	{
		printf("Enter text:");
		fgets(readbuf,SHMSZ,stdin);
		semaphore_P(consumer);
		sprintf(shm,"Message %4d from producer %d is \"%s\" \n",i, getpid(),readbuf);
		semaphore_V(producer);
		if(strcmp(readbuf,"end")==0)
			break;
	}
	return 0;
}

