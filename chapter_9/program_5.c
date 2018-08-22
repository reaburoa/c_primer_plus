#include <stdio.h>

void larger_of(double *a, double *b);

int main(void)
{
	double a, b;
	printf("Enter two number(q to quit):\n");
	while (scanf("%lf %lf", &a, &b) == 2)
	{
		printf("old value: a=%.4lf b=%.4lf\n", a, b);
		larger_of(&a, &b);
		printf ("a=%.4lf and b=%.4lf\n", a, b);
		printf("Enter two number(q to quit):\n");
	}
	
	return 0;
}

void larger_of(double *a, double *b)
{
	double larger = *a > *b ? *a : *b;
	*a = larger;
	*b = larger;
}
