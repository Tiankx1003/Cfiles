/*ex21 myshm.h"*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

#define SHMSZ	256
union semun
{
	int val;
	struct semid_ds	* buf;
	unsigned short 	*array;
};

int open_semaphore_set(key_t keyval,int numsems)
{
	int sid;
	if(!numsems)
		return -1;
	if((sid=semget(keyval,numsems,IPC_CREAT|0660))==-1)
		return -1;
	else
		return sid;
}
void init_a_semaphore(int sid, int semnum, int initval)
{
	union semun semopts;
	semopts.val=initval;
	semctl(sid, semnum,SETVAL,semopts);
}

int semaphore_P(int sem_id)
{
	struct sembuf sb;
	sb.sem_num=0;
	sb.sem_op=-1;
	sb.sem_flg=SEM_UNDO;
	
	if(semop(sem_id, &sb, 1)==-1)
	{
		printf("semaphore_P failed.\n");
		return 0;
	}
	return 1;
}

int semaphore_V(int sem_id)
{
	struct sembuf sb;
	sb.sem_num=0;
	sb.sem_op=1;
	sb.sem_flg=SEM_UNDO;
	if(semop(sem_id, &sb, 1)==-1)
	{
		printf("semaphore_V failed. \n");
		return 0;
	}
	return 1;
}

