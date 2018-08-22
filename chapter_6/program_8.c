#include<stdio.h>

int main(void)
{
	float a, b;
	double diff;
	double cheng;
	printf("Please input two float number, with q to quit:");
	while (scanf("%f %f", &a, &b) == 2) 
	{
		diff = a - b;
		cheng = a * b;
		printf("(%.2f - %.2f)/(%.2f * %.2f)=%.4lf\n", a, b, a, b, diff/cheng);
		printf("Please input two float number, with q to quit:");
	}

	return 0;
}
