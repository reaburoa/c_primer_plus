#include <stdio.h>

#define ROWS 5
#define COLS 6

void copy_ptr(double *dest, double *source, int num);
void show_arr(double (*arr)[COLS], int rows);

int main(void)
{
	double source[ROWS][COLS] = {
		{1.1, 2.2, 3.3, 4.4, 5.5, 6.6},
		{1.11, 2.22, 3.33, 4.44, 5.55, 6.66},
		{1.12, 2.23, 3.34, 4.45, 5.56, 6.67},
		{1.13, 2.24, 3.35, 4.46, 5.57, 6.68},
		{1.14, 2.25, 3.36, 4.47, 5.58, 6.69},
	};

	int i = 0;
	printf("Source array is:\n");
    show_arr(source, ROWS);
	
	double target[ROWS][COLS];
	for (i = 0; i < ROWS; i ++) {
		copy_ptr(target[i], source[i], COLS);
	}
	printf("Target array is:\n");
	show_arr(target, ROWS);
	return 0;
}

void show_arr(double arr[][COLS], int rows)
{
	int i, j;
	for (i = 0; i < rows; i ++) {
		for (j = 0; j < COLS; j ++)
			printf("%.2lf ", arr[i][j]);
		printf("\n");
	}
}

void copy_ptr(double *dest, double *source, int num)
{
	int i = 0;
	for (i = 0; i < num; i ++) 
		*(dest + i) = *(source + i);
}

