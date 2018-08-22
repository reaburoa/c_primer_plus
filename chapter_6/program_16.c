#include <stdio.h>

#define BASE_MONEY 100
#define YEAR_RATE 0.1
#define MIX_RATE 0.05

double power(double x, int y);

int main(void)
{
	double daphne_money = 0, deirdre_money = 0;
	int year = 1;
	do 
	{
		daphne_money = BASE_MONEY + year * BASE_MONEY * YEAR_RATE;
		deirdre_money = BASE_MONEY * power((1 + MIX_RATE), year);
		year ++;

		printf("year is %2d,", year - 1);
		printf("Daphne's money is $%.2lf,Deirdre's money is $%.2lf\n", daphne_money, deirdre_money);
	} while(deirdre_money < daphne_money);
	printf("After %d years Deirdre's money will lt Daphne's money\n", year - 1);
	return 0;
}

double power(double x, int y)
{
	int i = 1;
	double sum = 1;
	for (i = 1; i <= y; i ++)
	{
		sum *= x;	
	}

	return sum;
}
