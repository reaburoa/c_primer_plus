#include <stdio.h>

#define NUMS 7

void copy_ptr(double *dest, double *source, int num);

int main(void)
{
	double source[NUMS] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	double target[3];

	int i = 0;
	printf("Source array is:\n");
	for (i = 0; i < NUMS; i ++) 
		printf("%.1f ", *(source + i));
	printf("\n\n");
   
	copy_ptr(target, source + 2, 3);
	printf("Target array is:\n");
	for (i = 0; i < 3; i ++)
		printf("%.1f ", target[i]);
	printf("\n\n");
	
	return 0;
}

void copy_ptr(double *dest, double *source, int num)
{
	int i = 0;
	for (i = 0; i < num; i ++) 
		*(dest + i) = *(source + i);
}

