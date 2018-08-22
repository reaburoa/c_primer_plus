#include <stdio.h>

#define NUM 5

int get_max(const int *arr, int n);
void show_arr(const int *arr, int n);

int main(void)
{
	int arr[NUM] = {1, 21, 123, 0, -1};
	show_arr(arr, NUM);
	printf("the max num is %d\n", get_max(arr, NUM));
	return 0;
}

int get_max(const int *arr, int n)
{
	int i, max;
	max = *arr;
	for (i = 0; i < n; i ++)
	{
		if (*(arr + i) > max) {
			max = *(arr + i);
		}
	}

	return max;
}

void show_arr(const int *arr, int n)
{
	int i;
	printf("The Array is:\n");
	for (i = 0; i < n; i ++)
		printf("%d ", *(arr + i));
	printf("\n");
}

