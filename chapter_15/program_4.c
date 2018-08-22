#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void int2bin(char *pt, int n);
int checkBit(int n, int pos);

void int2bin(char *pt, int n)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	for (i = size - 1; i >= 0; i --, n >>= 1)
		pt[i] = (01 & n) + '0';
	pt[size] = '\0';
}

int checkBit(int n, int pos)
{
	const size_t STRLEN = CHAR_BIT * sizeof(int) + 1;
	char pt[STRLEN];
	int2bin(pt, n);
	printf("The string of %d is %s\n", n, pt);
	return (pt[pos - 1] == '1') ? 1 : 0;
}

int main()
{
	int one, pos;
	printf("Please enter a int number and a position(q to quit):\n");
	while (scanf("%d %d", &one, &pos) == 2)
	{
		printf("The bin string of %d postion %d number is %d\n", one, pos, checkBit(one, pos));
		printf("Please enter a int number(q to quit):\n");
	}
	printf("Done.\n");
	return 0;
}
