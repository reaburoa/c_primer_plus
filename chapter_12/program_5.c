#include <stdio.h>
#include <stdlib.h>

#define TOTAL 100

static unsigned long int next = 1;
void sort(int *arr, int n);
void display(const int *arr, int n);
unsigned int rrand(void);

int main(void)
{
	int *pt = (int *)malloc(TOTAL * sizeof(int));
	int i = 0;
	for (i = 0; i < TOTAL; i ++)
		*(pt + i ) = rrand();
	printf("Rand array is:\n");
	display(pt, TOTAL);
	sort(pt, TOTAL);
	printf("Sort desc array is:\n");
	display(pt, TOTAL);
	free(pt);
	return 0;
}

unsigned int rrand(void)
{
	next = next * 1103515245 + 12345;
	return (next /65535) % 10 + 1;
}

void display(const int *arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i ++)
		printf("%d ", *(arr + i));
	printf("\n");
}

void sort(int *arr, int n)
{
	int i, j;
	for (i = 0; i < n; i ++)
		for (j = i; j < n; j ++) 
			if (*(arr + j) > *(arr + i))
			{
				int temp;
				temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
}
