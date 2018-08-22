#include <stdio.h>

void get_data(int rows, int cols, double source[rows][cols]);
void get_ave_ar(double *ave, int rows, int cols, double ar[rows][cols]);
double get_ave(int rows, int cols, double ar[rows][cols]);
double get_max(int rows, int cols, double ar[rows][cols]);
void display(int rows, int cols, double ar[rows][cols]);
void display_one_ar(int rows, double ar[rows]);

int main(void)
{
	printf("Please input array rows and cols\n");
	int rows, cols;
	scanf("%d %d", &rows, &cols);
	printf("Program will store %d * %d array\n", rows, cols);
	
	double source[rows][cols];
	get_data(rows, cols, source);

	printf("The source data is:\n");
	display(rows, cols, source);
	double ave[rows];
	printf("The array row's ave is:\n");
	get_ave_ar(ave, rows, cols, source);
	display_one_ar(rows, ave);

	printf("The array's ave is:%.2lf\n", get_ave(rows, cols, source));
	printf("The max value is %.2lf\n", get_max(rows, cols, source));

	return 0;
}

void get_data(int rows, int cols, double source[rows][cols])
{
	int i = 0, j = 0;
	printf("This program will get %d numbers:\n", rows * cols);
	for (i = 0; i < rows; i ++) {
		printf("Enter the %d row %d number:\n", i + 1, cols);
		double tmp[cols];
		for (j = 0; j < cols; j ++) {
			scanf("%lf", &tmp[j]);
			source[i][j] = tmp[j];
		}
	}
}

void get_ave_ar(double *ave, int rows, int cols, double ar[rows][cols])
{
	int i, j;
	double subtotal;
	for (i = 0; i < rows; i ++) {
		for (j = 0, subtotal = 0; j < cols; j ++) {
			subtotal += ar[i][j];
		}
		*(ave + i) = subtotal / cols;
	}
}

double get_ave(int rows, int cols, double ar[rows][cols])
{
	int i, j;
	double total = 0;
	for (i =0; i < rows; i ++) {
		for (j = 0; j < cols; j ++)
			total += ar[i][j];
	}

	return total / (rows * cols);
}

double get_max(int rows, int cols, double ar[rows][cols])
{
	double max;
	int i, j;
	max = ar[0][0];
	for (i = 0; i < rows; i ++) {
		for (j = 0; j < cols; j ++) {
			if (ar[i][j] > max) {
				max = ar[i][j];
			}
		}
	}

	return max;
}

void display(int rows, int cols, double ar[rows][cols])
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i ++) {
		for (j = 0; j < cols; j ++) 
			printf("%-5.1lf ", ar[i][j]);
		printf("\n");
	}
	printf("\n");
}

void display_one_ar(int rows, double ar[rows])
{
	int i;
	for (i = 0; i < rows; i ++) {
		printf("%-5.1lf ", ar[i]);
	}
	printf("\n");
}
