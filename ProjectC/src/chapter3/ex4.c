#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	char	*ptr;
	for(i=1; i<argc;i++)
	{
		printf("%s: ",argv[i]);
		if(lstat(argv[i],&buf)<0)
		{	
			printf("error! \n");
			continue;
		}
		switch(S_IFMT&buf.st_mode)      /* �����ļ����� */
		{
			case S_IFREG: ptr="regular"; break;			/* ��ͨ�ļ� */
			case S_IFDIR:  ptr="directory"; break;			/* Ŀ¼�ļ� */
			case S_IFCHR: ptr="character special"; break;		/* �ַ��豸�ļ� */
			case S_IFBLK: ptr="block special"; break;		/* ���豸�ļ� */
			case S_IFIFO: ptr="fifo"; break;			/* �ܵ��ļ� */
			case S_IFLNK: ptr="symbolic  link"; break;		/* ���������ļ� */
			case S_IFSOCK: ptr="socket"; break;			/* socket�ļ� */
			default:ptr="unknown mode "; 
		}
		printf("%s \n",ptr);
	}
	return 0;
}
