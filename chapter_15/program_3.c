#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

void int2bin(char *pt, int n);
int openBitNum(char *pt);

int openBitNum(char *pt)
{
	int open_num = 0;
	while (*pt)
	{
		if ((*pt & 1) == 1)
			open_num ++;
		pt ++;
	}
	return open_num;
}

void int2bin(char *pt, int n)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	for (i = size - 1; i >= 0; i --, n >>= 1)
		pt[i] = (01 & n) + '0';
	pt[size] = '\0';
}

int main()
{
	const size_t STRLEN = CHAR_BIT * sizeof(int) + 1;
	int one;
	printf("Please enter a int number(q to quit):\n");
	while (scanf("%d", &one) == 1)
	{
		char pt[STRLEN];
		int2bin(pt, one);
		printf("You input number is %d and bin string is %s and open bit num is %d\n", one, pt, openBitNum(pt));

		printf("Please enter a int number(q to quit):\n");
	}
	
	printf("Done.\n");
	return 0;
}
