#include <stdio.h>

#define ALL_MONEY 1000000
#define YEAR_OUTPUT 100000
#define YEAR_RATE 0.08

double power(double x, int y);

int main(void)
{
	double balance = ALL_MONEY;
	int year = 1;
	do
	{
		double year_out_put = 0;
		int i = 1;
		for (i = 1; i <= year; i ++) 
		{
			year_out_put += YEAR_OUTPUT / power((1 + YEAR_RATE), i);
		}
        balance = (ALL_MONEY - year_out_put) * power((1 + YEAR_RATE), year);
		printf("year is %3d, balance is $%.2lf\n", year, balance);
		year ++;
	} while (balance >= YEAR_OUTPUT);
	printf("after %d year, balance is $%.2lf,%d years has no balance\n", year - 1, balance, year);
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

