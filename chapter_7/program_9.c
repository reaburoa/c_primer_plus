#include <stdio.h>
#include <math.h>

int isPrime(int n);

int main(void)
{
	int num;
	int i = 2;
	printf("Please input a num and program will print all prime below num, with below 1 to quit:\n");
	while (scanf("%d", &num) == 1)
	{
		if (num <= 1) break;
		for (i = 2; i <= num; i ++)
		{
			if (isPrime(i)) printf("%d ", i);
		}
		printf("\n");
		printf("Please input a num and program will print all prime below num, with below 1 to quit:\n");
	}
	return 0;
}

int isPrime(int n)
{
	int i = 2;
	int sqrt_num = (int)sqrt((double)n);
	int result = 1;
	for (i = 2; i <= sqrt_num; i ++)
	{
		if (n % i == 0) 
		{
			result = 0;
			break;
		}
	}
	return result;
}
