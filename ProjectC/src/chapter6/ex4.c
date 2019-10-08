/* ex4.c*/
#include <signal.h>

 void pr_mask(const char *str)
{
	sigset_t sigset;
	if(sigpromask(0, NULL, &sigset)<0)
	{
		printf("sigprocmask error");
		exit(0);
	}
	printf("%s", str);
	if(sigismember(&sigset, SIGINT))
		printf("SIGINT \n");
	if(sigismember(&sigset,SIGQUIT))
		printf("SIGQUIT \n");
	if(sigismember(&sigset, SIGUSR1))
		printf("SIGUSR1 \n");
	if(sigismember(&sigset, SIGALRM))
		printf("SIGALARM \n");
}
