#include <stdio.h>

int main(void)
{
	int min_num, max_num;
	int i;
	printf("Enter lower and upper integer limits:");
	while (scanf("%d %d", &min_num, &max_num) == 2) 
	{
		if (min_num >= max_num) 
		{
			break;
		}
		long sum = 0;
		for (i = min_num; i <= max_num; i ++) 
		{
			sum += i*i;
		}
		printf("The sums of the squares from %d to %d is %ld\n", min_num, max_num, sum);
	    printf("Enter lower and upper integer limits:");
	}
	printf("Done\n");
	return 0;
}
