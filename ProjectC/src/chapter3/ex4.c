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
		switch(S_IFMT&buf.st_mode)      /* 测试文件类型 */
		{
			case S_IFREG: ptr="regular"; break;			/* 普通文件 */
			case S_IFDIR:  ptr="directory"; break;			/* 目录文件 */
			case S_IFCHR: ptr="character special"; break;		/* 字符设备文件 */
			case S_IFBLK: ptr="block special"; break;		/* 块设备文件 */
			case S_IFIFO: ptr="fifo"; break;			/* 管道文件 */
			case S_IFLNK: ptr="symbolic  link"; break;		/* 符号链接文件 */
			case S_IFSOCK: ptr="socket"; break;			/* socket文件 */
			default:ptr="unknown mode "; 
		}
		printf("%s \n",ptr);
	}
	return 0;
}
