#include <stdio.h>

void sort(double *a, double *b, double *c);

int main(void)
{
	double a, b, c;
	printf("Please input three number(q to quit):");
	while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
	{
		printf("Old value is %.4lf %.4lf %.4lf\n", a, b, c);
		printf("Sort by asc is:");
		sort(&a, &b, &c);
		printf("New value is %.4lf %.4lf %.4lf\n", a, b, c);
		printf("Please input three number(q to quit):");
	}
	return 0;
}

void sort(double *a, double *b, double *c)
{
	double tmp;
	if (*a > *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
	if (*a > *c)
	{
		tmp = *a;
		*a = *c;
		*c = tmp;
	}
	if (*b > *c)
	{
		tmp = *b;
		*b = *c;
		*c = tmp;
	}
}

