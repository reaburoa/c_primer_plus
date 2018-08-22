#include <stdio.h>

double power(double n, int p);

int main(void)
{
	double x, xpow;
	int exp;

	printf("Enter a number and the positive integer power");
	printf(" to which\nthe number will raised.Enter q");
	printf(" to quit\n");
	while (scanf("%lf%d", &x, &exp) == 2)
	{
		xpow = power(x, exp);
		printf("%.3g to the power %d  id %.5g\n", x, exp, xpow);
		printf("Enter next pair of number or q to quit.\n");
	}
	printf("Hope you enjoyed this power trip --bye!\n");
	return 0;
}

double power(double n, int p)
{
	double pow = 1;
	if (n == 0 && p == 0) 
		return 1;
	if (n == 0)
		return 0;
	if (n != 0 && p == 0)
		return 1;
	int tmp = p >= 0 ? p : -p;
	pow = power(n, tmp - 1) * n;
	if (p < 0)
		pow = 1.0 / pow;
	return pow;
}
