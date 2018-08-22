#include <stdio.h>
#include <string.h>

#include "s_gets.h"

#define SIZE  50

char *revert_str(char *st);

int main(void)
{
	char str[SIZE];
	printf("Please input a string:\n");
	while (s_gets(str, SIZE) && str[0] != '\0') {
		printf("old string is %s\n", str);
		revert_str(str);
		printf("new string is %s\n", str);
		printf("Test again\n");
	}
	return 0;
}

char *revert_str(char *st)
{
	int length = strlen(st);
	int midle = length / 2;
	char *end;
	end  = st + length - 1;
	int i = 0;
	char tmp;
	while (i < midle)
	{
		tmp = *(st + i);
		*(st + i) = *(end - i);
		*(end - i) = tmp;
		i ++;
	}
	return st;
}
