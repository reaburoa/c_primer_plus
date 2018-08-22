#include <stdio.h>
int power(int x, int y);

int main(void)
{
	int num[8];
	int i = 0, j = 0;
	for (i = 0; i < 8; i ++) 
	{
		num[i] = power(2, i);
	}

	printf("The array is:\n");
	do 
	{
		printf("%d ", num[j]);
		j ++;
	} while(j < 8);
	
	printf("\nend\n");
	return 0;
}

int power(int x, int y)
{
	int i = 0;
	int sum = 1;
	for (i = 0; i < y; i ++)
	{
		sum *= x;
	}

	return sum;
}
