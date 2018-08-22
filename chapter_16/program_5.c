#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *getRandNumber(int *target, int *arr, int n, int m);
void display(int *arr, int n);

int *getRandNumber(int *target, int *arr, int n, int m)
{
	srand((unsigned int)time(0));
	int i = 0, index, tmp;
	int j = 0;
	m = m > n ? n : m;
	for (i = 0; i < m; i ++)
	{
		index = rand() % (n - 1);
		tmp = *(arr + index);
		*(target + i) = tmp;
		*(arr + index) = *(arr + (n - 1));
		*(arr + (n - 1)) = tmp;
		n --;
	}

	return target;
}

void display(int *arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i ++)
	{
		printf("%-2d ", *(arr+i));
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	printf("\n");
}

#define MAX 50
#define PICK 5

int main(void)
{
	int data[MAX];
	int target[PICK];

	int i = 0;
	for (i = 0; i < MAX; i ++)
		data[i] =  2 * i;
	printf("Init array data is:\n");
	display(data, MAX);
	char again;
	do
	{
		getRandNumber(target, data, MAX, PICK);
		printf("Rand array is:\n");
		display(target, PICK);
		printf("Do you want to again (y|n):");
		scanf("%c", &again);
		again = tolower(again);
		while (getchar() != '\n')
			continue;
	} while (again == 'y');

	return 0;
}
