#include <stdio.h>

double sum(double one, double two);
double chen(double one, double two);
void displayMenu();

double sum(double one, double two)
{
	return one + two;
}

double cheng(double one, double two)
{
	return one * two;
}

void displayMenu()
{
	printf("Please choice your choose:\n");
	printf("1) get sum of two number\n");
	printf("2) get ji of two number\n");
	printf("q to quit\n");
}

#define MAX 2
int main(void)
{
	double (*pf[MAX])(double, double) = {sum, cheng};
	int choose;
	displayMenu();
	double one = 1;
	double two = 2;

	while (scanf("%d", &choose) == 1)
	{
		while (getchar() != '\n')
			continue;
		if (choose < 1 || choose > 2)
		{
			displayMenu();
			continue;
		}
		double (*pf)(double, double);
		switch (choose)
		{
			case 1:
				pf = sum;
				printf("%.2f + %.2f = %.2f\n", one, two, pf(one, two));
				break;
			case 2:
				pf = cheng;
				printf("%.2f * %.2f = %.2f\n", one, two, (*pf)(one, two));
				break;
		}
		displayMenu();
	}

	printf("Done\n");
	return 0;
}
