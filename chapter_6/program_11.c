#include <stdio.h>

int main(void)
{
	int number[8];
	printf("Enter 8 integer number:");
	for (int i = 0; i < 8; i ++) 
	{
		scanf("%d", &number[i]);
	}
	for (int i = 7; i >= 0; i --) 
	{
		printf("%d ", number[i]);
	}

	printf("\nDone\n");
	return 0;
}
