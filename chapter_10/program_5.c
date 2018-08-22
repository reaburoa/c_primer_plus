#include <stdio.h>

#define NUM 5

double get_max_min_diff(const double *arr, int n);
void show_arr(const double *arr, int n);

int main(void)
{
	double arr[NUM] = {1.2, 2.1, 12.3, 0.1, -1.3};
	show_arr(arr, NUM);
	double max_min_diff = get_max_min_diff(arr, NUM);
	printf("the max and min diff is %.4lf\n", max_min_diff);
	return 0;
}

double get_max_min_diff(const double *arr, int n)
{
	int i;
	double max, min;
	max = *arr;
	min = *arr;
	for (i = 0; i < n; i ++)
	{
		if (*(arr + i) > max) {
			max = *(arr + i);
		}
		if (*(arr + i) < min) {
			min = *(arr + i);
		}
	}
	
	return max - min;
}

void show_arr(const double *arr, int n)
{
	int i;
	printf("The Array is:\n");
	for (i = 0; i < n; i ++)
		printf("%.4lf ", *(arr + i));
	printf("\n");
}

