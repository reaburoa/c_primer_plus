#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#include "s_gets.h"

bool checkVal(char *pbin);
int bin2int(char *pbin);

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

int main(void)
{
	const size_t STRLEN = CHAR_BIT * sizeof(int) + 1;
	char pbin[STRLEN];
	printf("Please input a string with char is 1 or 0:\n");
	while (s_gets(pbin, STRLEN) && pbin[0] != '\0')
	{
		if (!checkVal(pbin))
			printf("%s is formed by 0 or 1\n", pbin);
		else
			printf("%s to int is %d\n", pbin, bin2int(pbin));

		printf("Please input a string with char is 1 or 0:\n");
	}
	printf("Done.\n");
	return 0;
}
