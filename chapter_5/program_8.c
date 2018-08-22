#include <stdio.h>

int main(void)
{
	int first, second;
	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand:");
	scanf("%d", &second);
	printf("Now enter the first operand:");
	while (scanf("%d", &first) == 1)
	{
		if (first <= 0)
		{
			printf("Program will end\n");
			break;
		}
		printf("%d %% %d is %d\n", first, second, first % second);
		printf("Enter next number for first operand(<=0 to quit):");
	}

	return 0;
}
