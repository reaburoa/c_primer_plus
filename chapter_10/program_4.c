#include <stdio.h>

#define NUM 5

int get_max_addr(const double *arr, int n);
void show_arr(const double *arr, int n);

int main(void)
{
	double arr[NUM] = {1, 21, 123, 0, -1};
	show_arr(arr, NUM);
	int max_addr = get_max_addr(arr, NUM);
	printf("the max num is %.4lf, and it addr is %d\n", arr[max_addr], max_addr);
	return 0;
}

int get_max_addr(const double *arr, int n)
{
	int i, max;
	max = *arr;
	int max_addr = 0;
	for (i = 0; i < n; i ++)
	{
		if (*(arr + i) > max) {
			max = *(arr + i);
			max_addr = i;
		}
	}
	
	return max_addr;
}

void show_arr(const double *arr, int n)
{
	int i;
	printf("The Array is:\n");
	for (i = 0; i < n; i ++)
		printf("%.4lf ", *(arr + i));
	printf("\n");
}

