#include <stdio.h>
#include <stdbool.h>

#define MAX 10

unsigned int findValue(const int *arr, int n, int val);

unsigned int findValue(const int *arr, int n, int val)
{
	int min = 0;
	int max = n - 1;
	int mid;
	int find = 0;
	while (min < max)
	{
		mid = (min + max) / 2;
		if (*(arr + mid) > val)
			max = mid - 1;
		else if (*(arr + mid) < val)
			min = mid + 1;
		else
		{
			find = 1;
			break;
		}
	}
	if (*(arr + min) == val)
		find = 1;
	return find;
}

int main(void)
{
	int arr[MAX] = {1, 23, 33, 42, 45, 56, 77, 98, 129, 133};
	int num;
	int find;
	printf("Please input a number to find:\n");
	while (scanf("%d", &num) == 1)
	{
		find = findValue(arr, MAX, num);
		printf("Find %d in arr ret is:%d\n", num, find);
		printf("Please enter a number to find(q to quit):\n");
	}
	return 0;
}
