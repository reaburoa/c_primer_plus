#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double power(double base, int p);

int main(int argc, char *argv[])
{
	if (argc < 3)
		printf("Params is error, must be with base number and power\n");
	else
	{
		int i = 0;
		printf("%s %s %s\n", argv[0], argv[1], argv[2]);
		double ret = power(atof(argv[1]), atoi(argv[2]));
		printf("%s power %s is %.4lf\n", argv[1], argv[2], ret);
	}
	return 0;
}

double power(double base, int p)
{
	int i = 0;
	double ret = 1;
	for (i = 0; i < p; i ++)
		ret *= base;
	return ret;
}
