#include <stdio.h>

#define ROWS 3
#define COLS 5

void copy(int rows, int cols, double dest_arr[rows][cols], double src_arr[rows][cols]);
void display(int rows, int cols, double ar[rows][cols]);

int main(void)
{
	int rows = 3;
	int cols = 5;
	double source[ROWS][COLS] = 
	{
		{4.5, 4.4, 4.3, 4.1, 4.2},
		{8.5, 8.2, 1.2, 1.3, 1.4},
		{9.1, 8.5, 6.7, 6.8, 2.1},
	};
	double target[rows][cols];
	printf("The source array is;\n");
	display(rows, cols, source);
	copy(rows, cols, target, source);
	printf("The copy array is:\n");
	display(rows, cols, target);

	return 0;
}

void copy(int rows, int cols, double dest_arr[rows][cols], double src_arr[rows][cols])
{
	int i, j;
	for (i = 0; i < rows; i ++)
		for (j = 0; j < cols; j ++)
			dest_arr[i][j] = src_arr[i][j];
}
void display(int rows, int cols, double ar[rows][cols])
{
	int i, j;
	for (i = 0; i < rows; i ++) {
		for (j = 0; j < cols; j ++)
			printf("%.1lf ", ar[i][j]);
		printf("\n");
	}
}

