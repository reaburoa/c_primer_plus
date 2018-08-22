#include <stdio.h>
#include <stdlib.h>

#define TOTAL 1000

static unsigned long int next = 1;
unsigned int rrand(void);
void ssrand(unsigned int seed);
void display(int *ar, int n);

int main(int argc, char **argv)
{
	if (argc == 3)
		ssrand(atoi(argv[2]));
	int i = 0, j = 0;
	int *pt = (int *)malloc(TOTAL * sizeof(int));
	for (i = 0; i < TOTAL; i ++)
		*(pt + i) = rrand();
	int base[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int stat[10] = {0};
	for (i = 0; i < TOTAL; i ++)
		for (j = 0; j < 10; j ++)
			if (pt[i] == base[j])
				stat[j] ++;		
	printf("rand array is:");
	display(pt, TOTAL);
	printf("number stat is:\n");
	for (i = 0; i < 10; i ++)
		printf("%d - %d\n", i + 1, stat[i]);
	free(pt);
	return 0;
}

void display(int *ar, int n)
{
	int i = 0;
	for (i = 0; i < n; i ++)
		printf("%d ", ar[i]);
	printf("\n");
}

unsigned int rrand(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65535) % 10 + 1;
}
void ssrand(unsigned int seed)
{
	next = seed;
}

