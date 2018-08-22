#include <stdio.h>

void sum_store(double *desc, double *first, double *second, int num);
void display(double *arr, int num);

#define COLS 4

int main(void)
{
	double first[COLS] = {2, 4, 5, 8};
	double second[COLS] = {1, 0, 4, 6};
	printf("The first array is:\n");
	display(first, COLS);
	printf("The second array is:\n");
	display(second, COLS);
	printf("The array sum is:\n");
	double sum_arr[COLS];
	sum_store(sum_arr, first, second, COLS);
	display(sum_arr, COLS);

	return 0;
}

void display(double *arr, int num)
{
	int i;
	for (i = 0; i < num; i ++) 
		printf("%-4.1lf ", *(arr + i));
	printf("\n");
}

void sum_store(double *desc, double *first, double *second, int num)
{
	int i;
	for (i = 0; i < num; i ++) {
		*(desc + i) = *(first + i) + *(second + i);
	}
}
