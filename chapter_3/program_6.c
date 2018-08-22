#include <stdio.h>

int main(void)
{
	float kuatuo;
	const float shuifenzi = 3.0e-23;
	const float shuig = 950.0;
	printf("Please input water kuatuo numbers:");
	scanf("%f", &kuatuo);
	printf("shui fenzi numbers is %e\n", kuatuo * shuig / shuifenzi);
	return 0;
}
