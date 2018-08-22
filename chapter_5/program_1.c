#include <stdio.h>

#define SIXTY 60

int main(void)
{
	int number;
	printf("Please enter an integer for minutes:\n");
	while (scanf("%d", &number) == 1)
	{
		if (number <= 0)
			break;
		printf("hour %d minutes %d\n", number/SIXTY, number%SIXTY);
		printf("Please enter an integer for minutes:\n");

	}

	return 0;
}
