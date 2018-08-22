#include <stdio.h>

#define ROWS 3
#define COLS 5

void multi(int ar[][COLS], int rows);
void display(int ar[][COLS], int rows);

int main(void)
{
	int rows = 3;
	int cols = 5;
	int source[ROWS][COLS] = 
	{
		{45, 44, 43, 41, 42},
		{85, 82, 12, 13, 14},
		{91, 85, 67, 68, 21},
	};
	printf("The source array is;\n");
	display(source, ROWS);
	multi(source, ROWS);
	printf("The nulti array is:\n");
	display(source, ROWS);
	return 0;
}

void multi(int ar[][COLS], int rows)
{
	int i;
	int j;
	for (i = 0; i < rows; i ++) 
		for (j = 0; j < COLS; j ++)
			ar[i][j] *= 2;
}
void display(int ar[][COLS], int rows)
{
	int i, j;
	for (i = 0; i < rows; i ++) {
		for (j = 0; j < COLS; j ++)
			printf("%-5d ", ar[i][j]);
		printf("\n");
	}
}

