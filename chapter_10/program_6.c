#include <stdio.h>

#define NUM 5

void sort(double *arr, int n);
void show_arr(const double *arr, int n);

int main(void)
{
	double arr[NUM] = {1.2, 2.1, 12.3, 3.5, -1.3};
	printf("Old array is:\n");
	show_arr(arr, NUM);
	sort(arr, NUM);
	printf("Sort array is:\n");
	show_arr(arr, NUM);
	return 0;
}

void sort(double *arr, int n)
{
	int i, j;
	double tmp;
	for (i = 0; i < n; i ++)
		for (j = i; j < n; j ++)
			if (arr[i] < arr[j]) {
				tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
			}

}

void show_arr(const double *arr, int n)
{
	int i;
	for (i = 0; i < n; i ++)
		printf("%.4lf ", *(arr + i));
	printf("\n");
}

