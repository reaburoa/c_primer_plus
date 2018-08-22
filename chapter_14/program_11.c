#include <stdio.h>
#include <math.h>

void transform(double *source, double *target, int n, double (*pf)(double));
double twice(double n);
double sqrt(double n);
void displayArr(double *arr, int n);

#define ARR_MAX 20

void transform(double *source, double *target, int n, double (*pf)(double))
{
	int i = 0;
	for (i = 0; i < n; i ++)
	{
		target[i] = (*pf)(source[i]);
	}
}

double twice(double n)
{
	return 2 * n;
}
double addTwo(double n)
{
	return 2 + n;	
}

void displayArr(double *arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i ++)
	{
		if (i > 0 && i % 10 == 0)
			printf("\n");
		printf("%-6.2f ", arr[i]);
	}
	printf("\n");
}

int main(void)
{
	double source[ARR_MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	double target[ARR_MAX];
	printf("The source array is:\n");
	displayArr(source, ARR_MAX);
	printf("The first transform, callback function is sin:\n");
	double (*pf)(double);
	pf = sin;
	transform(source, target, ARR_MAX, pf);
	printf("The target array is:\n");
	displayArr(target, ARR_MAX);
	printf("The second transform, callback function is cos:\n");
	pf = cos;
	transform(source, target, ARR_MAX, pf);
	printf("The target array is:\n");
	displayArr(target, ARR_MAX);
	printf("The third transform, callback function is twice:\n");
	pf = twice;
	transform(source, target, ARR_MAX, pf);
	printf("The target array is:\n");
	displayArr(target, ARR_MAX);
	printf("The forth transform, callback function is addTwo:\n");
	pf = addTwo;
	transform(source, target, ARR_MAX, pf);
	printf("The target array is:\n");
	displayArr(target, ARR_MAX);
	return 0;
}
