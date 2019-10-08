#include <stdio.h>

#define BEGIN 1;	


int main(int argc, char *argv[])
{
	int c, characters, lines, words, state;
	state=0;
	characters=words=lines=0;
	while((c=getchar())!='0')
	{
		characters++;
		switch(c)
		{
		case '\n':
			lines++;
			state=0;
			break;
		case ' ':
			state=0;
			break;
		case '\t':
			state=0;
			break;
		default: 
			if(state==0)
				{
					state=BEGIN;
					words++;
				}
			break;
		}
	}
	printf("Thereis %d characters, %d words ,%d lines.\n",characters, words, lines);

}
