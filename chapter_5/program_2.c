#include <stdio.h>

int main(void)
{
	int number;
	printf("Please input a number:\n");
	scanf("%d", &number);
	int i = number, limit = number + 10;
	for (i = number; i <= limit; i ++)
	{
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}
