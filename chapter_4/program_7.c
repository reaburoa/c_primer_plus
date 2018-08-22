#include <stdio.h>
#include <float.h>

int main(void)
{
	double first = 1.0/3.0;
	float second = 1.0/3.0;
	printf("first\tsecond\n");
	printf("%.6f\t%.6lf\n", first, second);
	printf("%.12f\t%.12lf\n", first, second);
	printf("%.16f\t%.16lf\n", first, second);
	printf("Float number precision is %d\n", FLT_DIG);
	printf("Double number precision is %d\n", DBL_DIG);
	return 0;
}
