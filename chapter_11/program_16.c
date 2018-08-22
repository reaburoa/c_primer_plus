#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "s_gets.h"

#define SIZE 80

char *toUpper(char *st);
char *toLower(char *st);

int main(int argc, char *argv[])
{
	char str[SIZE];
	printf("Please input a string:\n");
	s_gets(str, SIZE);
	printf("You input string is:\n");
	if (argc < 2)
	{
		printf("%s\n", str);
		return 0;
	}
	if (strcmp(argv[1], "-u") == 0)
		toUpper(str);
	else if (strcmp(argv[1], "-l") == 0)
		toLower(str);
	printf("%s\n", str);
	return 0;
}

char *toUpper(char *st)
{
	while (*st)
	{
		*st = toupper(*st);
		st ++;
	}
}

char *toLower(char *st)
{
	while (*st)
	{
		*st = tolower(*st);
		st ++;
	}
}

