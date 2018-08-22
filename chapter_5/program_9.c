#include <stdio.h>

void Temperatures(double huashi);

int main(void)
{
	double huashi;
	printf("Please input huashi:");
	while (scanf("%lf", &huashi) == 1)
	{
		if (huashi < 0)
			break;
		Temperatures(huashi);
		printf("Please input next huashi (< 0 to quit):");
	}
	return 0;
}

void Temperatures(double huashi)
{
	double sheshi = 0;
	double kaishi = 0;

	const double sheshi_2_kaishi = 273.16;
	const double huashi_2_sheshi = 32.0;
	const double five = 5.0;
	const double nine = 9.0;
	sheshi = five / nine * (huashi - huashi_2_sheshi);
	kaishi = sheshi + sheshi_2_kaishi;
	printf("sheshi is %.2lf\n", sheshi);
	printf("kaishi is %.2lf\n", kaishi);
}
