#include <stdio.h>

long double cube(double num);

int main(void)
{
	double number;
	printf("Please input a number and will get the cube:");
	scanf("%lf", &number);
	printf("You input number is %.4lf\n", number);
	long double multify = cube(number);
	printf("The cube is %.4Lf\n", multify);
	return 0;
}

long double cube(double num)
{
	long double result = num * num * num;
	return result;
}
