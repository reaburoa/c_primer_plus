#include <stdio.h>

#define TIAOHE(X, Y) (1.0/((1.0/(X) + 1.0/(Y))/2))

int main(void)
{
	int a, b;
	printf("Please enter two number:\n");
	while (scanf("%d %d", &a, &b) == 2)
	{
		printf("Your input is below and they tiaohe number:\n");
		printf("a=%d,b=%d,tiaohe is %.4f\n", a, b, TIAOHE(a, b));

		printf("Please enter two number:\n");
	}

	return 0;
}

