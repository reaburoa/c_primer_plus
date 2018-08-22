#include <stdio.h>
double division(float a, float b);

int main(void)
{
	float a, b;
	double diff, product;
	printf("Please input two number, with q to quit:");
	while (scanf("%f %f", &a, &b) == 2) 
	{
		printf("(%.2f-%.2f)/(%.2f*%.2f)=%.4lf\n", a, b, a, b, division(a, b));
	    printf("Please input two number, with q to quit:");
	}

	return 0;
}

double division(float a, float b)
{
	return (a - b)/(a * b);
}
