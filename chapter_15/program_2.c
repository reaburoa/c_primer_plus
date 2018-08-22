#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "s_gets.h"

bool checkVal(char *pbin);
int bin2int(char *pbin);
char *int2bin(char *pt, int n);
void showBstr(const char *str);

void showBstr(const char *str)
{
	int i = 0;
	while (str[i])
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
			putchar(' ');
	}
}

char *int2bin(char *pt, int n)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	for (i = size - 1; i >= 0; i --, n >>= 1)
		pt[i] = (01 & n) + '0';
	pt[size] = '\0';

	return pt;
}

bool checkVal(char *pbin)
{
	bool valid = true;
	while (valid && *pbin != '\0')
	{
		if (*pbin != '0' && *pbin != '1')
			valid = false;
		pbin ++;
	}

	return valid;
}

int bin2int(char *pbin)
{
	int val = 0;
	while (*pbin != '\0')
	{
		val = 2 * val + (*pbin - '0');
		pbin ++;
	}
	
	return val;
}

int main(int argc, char *argv[])
{
	if (argc > 3 || argc <= 1)
	{
		printf("Use this Command with command bin bin\n");
		exit(EXIT_FAILURE);
	}
	const size_t STRLEN = CHAR_BIT * sizeof(int) + 1;
	int one, two;
	if (!checkVal(argv[1]) || !checkVal(argv[2]))
	{
		printf("%s,%s is not formed with 1 or 0\n", argv[1], argv[2]);
		exit(EXIT_FAILURE);
	}
	one = bin2int(argv[1]);
	two = bin2int(argv[2]);
	printf("first param is %s and tranform into int is %d\n", argv[1], one);
	printf("second param is %s and tranform into int is %d\n", argv[2], two);
	int f_one = ~one;
	char pt[STRLEN];
	printf("%s qufan is %s\n", argv[1], int2bin(pt, f_one));
	int f_two = ~two;
	printf("%s qufan is %s\n", argv[2], int2bin(pt, f_two));
	int and = one & two;
	printf("%s & %s is %s\n", argv[1], argv[2], int2bin(pt, and));
	int or = one | two;
	printf("%s | %s is %s\n", argv[1], argv[2], int2bin(pt, or));
	int xor = one ^ two;
	printf("%s ^ %s is %s\n", argv[1], argv[2], int2bin(pt, xor));
	
	printf("Done.\n");
	return 0;
}
