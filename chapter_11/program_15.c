#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "s_gets.h"

#define SIZE 10

int toi(char *st);
int power(int base, int p);

int main(void)
{
	char st[SIZE];
	int ret;
	printf("Please input a string,program will print number:\n");
	while (s_gets(st, SIZE) && st[0] != '\0')
	{
		printf("you input string is %s\n", st);
		printf("convert to digit is %d\n", toi(st));
		printf("Test again\n");
	}
	return 0;
}

int toi(char *st)
{
	int length = strlen(st);
	int ret = 0;
	while (*st)
	{
		if (!isdigit(*st))
			return 0;
		length --;
		if (length < 0)
			break;
		int pow = power(10, length);
		ret += (*st - 48) * pow;
		st ++;
	}

	return ret;
}

int power(int base, int p)
{
	int i = 0;
	int ret = 1;
	for (i = 0; i < p; i ++)
		ret *= base;
	return ret;
}
