#include <stdio.h>

int main(void)
{
	int sum = 0;
	int count;
	printf("Please input a number:");
	while (scanf("%d", &count) == 1)
	{
		for (int i = 1; i <= count; i ++)
			sum += i;
		printf("Sum = %d\n", sum);
		sum = 0;
		printf("Please input a number:");
	}

	return 0;
}
