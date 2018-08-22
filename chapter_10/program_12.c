#include <stdio.h>

#define MONTHS 12
#define YEARS 5

double year_average(double ar[][MONTHS], int years);
double month_average(double *month_ave, double (*ave)[MONTHS], int years);
void display(int year, int month, double rain[year][month]);

int main(void)
{
	double rain[YEARS][MONTHS] = 
	{
		{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
		{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
		{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
		{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
		{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
	};
	printf("The source data is:\n");
	display(YEARS, MONTHS, rain);

	printf(" YEAR	RAINFALL (inches)\n");
	printf("\nThe yearly average is %.1lf inches.\n\n", year_average(rain, YEARS));
	printf("Monthly average:\n\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
	double month_ave[MONTHS];
	month_average(month_ave, rain, YEARS);
	int i = 0;
	for (i = 0; i < MONTHS; i ++) 
		printf("%-.1lf ", month_ave[i]);
	printf("\n");

	return 0;
}

double year_average(double ar[][MONTHS], int years)
{
	int month = 0;
	int year = 0;
	double total;
	double subtot;
	for (year = 0, total = 0; year < years; year ++) 
	{
		for (month = 0, subtot = 0; month < MONTHS; month ++) {
			subtot += *(*(ar + year) + month); 
		}
		total += subtot;
		printf("%-5d %-10.1lf\n", 2010+year, subtot);
	}

	return total / years;
}

double month_average(double *month_ave, double (*ave)[MONTHS], int years)
{
	int month;
	int year;
	double subtot;
	for (month = 0; month < MONTHS; month ++)
	{
		for (year =0, subtot = 0; year < years; year ++)
			subtot += *(ave[year] + month);
		*(month_ave + month) = subtot / years;
	}
}

void display(int year, int month, double rain[year][month])
{
	int i, j;
	for (i = 0; i < year; i ++) {
		for (j = 0; j < month; j ++)
			printf("%-5.2lf ", rain[i][j]);
		printf("\n");
	}
}
