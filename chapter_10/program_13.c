#include <stdio.h>

#define ROWS 3
#define COLS 5

void get_data(double source[ROWS][COLS]);
void get_ave_ar(double *ave, double (*ar)[COLS], int rows);
double get_ave_value(double *ar, int nums);
double get_ave(double (*ar)[COLS], int rows);
double get_max(double (*ar)[COLS], int rows);
void display(double ar[][COLS], int rows);

int main(void)
{
	double source[ROWS][COLS];
	get_data(source);
	printf("The source data is:\n");
	display(source, ROWS);
	double ave[ROWS];
	int i = 0;
	printf("The array row's ave is:\n");
	for (i = 0; i < ROWS; i ++) {
		ave[i] = get_ave_value(source[i], COLS);
		printf("%.2lf ", ave[i]);
	}
	printf("\n");
	printf("The array's ave is:%.2lf\n", get_ave(source, ROWS));
	printf("The max value is %.2lf\n", get_max(source, ROWS));

	return 0;
}

void get_data(double source[ROWS][COLS])
{
	int nums = ROWS * COLS;
	int i = 0, j;
	printf("This program will get %d numbers:\n", nums);
	for (j = 0; j < ROWS; j ++) {
		printf("Enter the %d row %d number:\n", j + 1, COLS);
		double tmp[COLS];
		for (i =0; i < COLS; i ++) {
			scanf("%lf", &tmp[i]);
			source[j][i] = tmp[i];
		}
	}
}

double get_ave_value(double *ar, int nums)
{
	double total = 0;
	int i;
	for (i = 0; i < nums; i ++)
		total += ar[i];
	return total / nums;
}

void get_ave_ar(double *ave, double (*ar)[COLS], int rows)
{
	int i, j;
	double subtotal;
	for (i = 0; i < rows; i ++)
	{
		for (j = 0, subtotal = 0; j < COLS; j ++)
		{
			subtotal += ar[i][j];
		}
		*(ave + i) = subtotal / COLS;
	}
}

double get_ave(double (*ar)[COLS], int rows)
{
	int i, j;
	double total = 0;
	for (i =0; i < rows; i ++) {
		for (j = 0; j < COLS; j ++)
			total += ar[i][j];
	}

	return total / (rows * COLS);
}

double get_max(double (*ar)[COLS], int rows)
{
	double max;
	int i, j;
	max = ar[0][0];
	for (i = 0; i < rows; i ++) {
		for (j = 0; j < COLS; j ++) {
			if (ar[i][j] > max) {
				max = ar[i][j];
			}
		}
	}

	return max;
}

void display(double ar[][COLS], int rows)
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i ++) {
		for (j = 0; j < COLS; j ++) 
			printf("%-5.1lf ", ar[i][j]);
		printf("\n");
	}
}

