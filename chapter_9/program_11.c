#include <stdio.h>

unsigned long Fibonacci(unsigned n);

int main()
{
	printf("This program will compute fib array\n");
	unsigned n;
	printf("Please enter a num(q to quit):");
	while (scanf("%d", &n) == 1)
	{
		printf("The fib array is:\n");
		Fibonacci(n);
		printf("Please enter a num(q to quit):");
	}
	return 0;
}

unsigned long Fibonacci(unsigned n)
{
	unsigned current, next;
	current = next = 1;
	int i, toway;
	for (i = 1; i <= n; i ++)
	{
		printf("%d ", current);
		toway = current + next;
		current = next;
		next = toway;
	}
	printf("\n");
}

