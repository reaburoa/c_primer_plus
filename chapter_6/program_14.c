#include <stdio.h>

int main(void)
{
	double a[8];
	printf("Please input 8 numbers:");
	int i = 0;
	for (i = 0; i < 8; i ++)
	{
		scanf("%lf", &a[i]);
	}
	double b[8];
	b[0] = a[0];
	for (i = 1; i < 8; i ++)
	{
		b[i] = b[i - 1] + a[i]; 
	}
	for (i = 0; i < 8; i ++)
	{
		printf("%10.2lf\t", a[i]);
	}
	printf("\n");
	for (i = 0; i < 8; i ++)
	{
		printf("%10.2lf\t", b[i]);
	}
	printf("\n");
	return 0;
}
