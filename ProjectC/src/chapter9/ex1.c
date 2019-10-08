/*ex1.c*/
#include <stdlib.h>
#include <stdio.h>
#include <mysql/mysql.h>
MYSQL *conn_ptr;

int main()
{
	conn_ptr=mysql_init(NULL);
	if(!conn_ptr)
	{
		fprintf(stderr,"mysql_init failed!\n");
		return -1;
	}	
	conn_ptr=mysql_real_connect(conn_ptr,"localhost","test","test","testdb", 0, NULL,0);
	if(conn_ptr)
		printf("Connection succeed!\n");
	else
	{
		printf("Connection failed!\n");
		return -2;
	}
	mysql_close(conn_ptr);
	printf("Connection closed.\n");
	return 0;
}
