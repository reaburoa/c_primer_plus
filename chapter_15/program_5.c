#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void int2bin(char *pt, int n);
unsigned int rotate_1(unsigned int n, unsigned int rotate);

void int2bin(char *pt, int n)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	for (i = size - 1; i >= 0; i --, n >>= 1)
		pt[i] = (01 & n) + '0';
	pt[size] = '\0';
}

unsigned int rotate_1(unsigned int n, unsigned int rotate)
{
	const size_t size = CHAR_BIT * sizeof(int);
	rotate %= size;
	unsigned int overflow;
	overflow = n >> (size - rotate);
	
	return n << rotate | overflow;	
}

int main()
{
	int one, rotate;
	const size_t size = CHAR_BIT * sizeof(int) + 1;
	printf("Please enter a int number and a rotate(q to quit):\n");
	while (scanf("%u %u", &one, &rotate) == 2)
	{
		printf("You input number is %u and rotate is %u\n", one, rotate);
		int rotate_num = rotate_1(one, rotate);
		char pt[size];
		printf("%u rotate number is %d\n", one, rotate_num);
		int2bin(pt, one);
		printf("The bin string of %d is %s\n", one, pt);
		int2bin(pt, rotate_num);
		printf("The bin string of roteate number %d is %s\n", rotate, pt);
		printf("Please enter a int number(q to quit):\n");
	}
	printf("Done.\n");
	return 0;
}
