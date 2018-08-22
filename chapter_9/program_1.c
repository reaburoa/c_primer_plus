#include <stdio.h>

double min(double a, double b);

int main(void)
{
	double x, y;
	printf("Please enter two number then will give the lower number(q to quit):\n");
	while (scanf("%lf %lf", &x, &y) == 2)
	{
		printf("The lower number is:");
		printf("%.6lf\n", min(x, y));
		printf("Please enter two number then will give the lower number(q to quit):\n");
	}
	return 0;
}

double min(double a, double b)
{
	return a > b ? b : a;
}

