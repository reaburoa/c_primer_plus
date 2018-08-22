#include <stdio.h>

#define NUMS 5

void copy_arr(double *dest, double *source, int num);
void copy_ptr(double *dest, double *source, int num);
void copy_ptrs(double *dest, double *source, double *source_end);

int main(void)
{
	double source[NUMS] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[NUMS];
	double target2[NUMS];
	double target3[NUMS];

	int i = 0;
	printf("Source array is:");
	for (i = 0; i < NUMS; i ++) 
		printf("%.1f ", *(source + i));
	printf("\n\n");
   
	copy_arr(target1, source, NUMS);
	printf("Target1 array is:");
	for (i = 0; i < NUMS; i ++)
		printf("%.1f ", target1[i]);
	printf("\n\n");

	copy_ptr(target2, source, NUMS);
	printf("Target2 array is:");
	for (i = 0; i < NUMS; i ++)
		printf("%.1f ", target2[i]);
	printf("\n\n");
	
	copy_ptrs(target3, source, source + NUMS);
	printf("Target3 array is:");
	for (i = 0; i < NUMS; i ++)
		printf("%.1f ", target3[i]);
	printf("\n\n");
	return 0;
}


void copy_arr(double *dest, double *source, int num)
{
	int i = 0;
	for (i = 0; i < num; i ++)
	{
		dest[i] = source[i];
	}
}

void copy_ptr(double *dest, double *source, int num)
{
	int i = 0;
	for (i = 0; i < num; i ++) 
		*(dest + i) = *(source + i);
}

void copy_ptrs(double *dest, double *source, double *source_end)
{
	while (source < source_end) {
		*dest = *source;
		source ++;
		dest ++;
	}
}

