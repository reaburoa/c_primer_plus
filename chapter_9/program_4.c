#include <stdio.h>

double tiaohe_avg(double a, double b);

int main(void)
{
	double a, b;
	printf("This program will get tiaohe_avg of two number!\n");
	printf("Please enter two number(q to quit):");
	while (scanf("%lf %lf", &a, &b) == 2)
	{
		printf("The tiaohe_avg is %.4lf!\n", tiaohe_avg(a, b));
		printf("Please enter two number(q to quit):");
	}

	return 0;
}

double tiaohe_avg(double a, double b)
{
	double avg = (1.0 / a + 1.0 / b) / 2;

	return 1.0 / avg;
}

