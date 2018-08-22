#include <stdio.h>

int main(void)
{
	float param;
	printf("Please input a float number:");
	scanf("%f", &param);
	printf("The number is %f and e %e\n", param, param);

	return 0;
}
