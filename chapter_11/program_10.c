#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "s_gets.h"

#define SIZE 80

char *del_space(char *st);

int main(void)
{
	char str[SIZE];
	printf("Please input a string,program will delete space:\n");
	while (s_gets(str, SIZE) && str[0] != '\0')
	{
		printf("You input string is:%s\n", str);
		del_space(str);
		printf("the string after deal:%s\n", str);
		printf("Test again\n");
	}
	return 0;
}

char *del_space(char *st)
{
	char *pos;
	while (*st)
	{
		if (isspace(*st)) 
		{
			pos = st;
			do
			{
				*pos = *(pos + 1);
				pos ++;
			} while (*pos);
		}
		else
			st ++;
	}
	return st;
}
