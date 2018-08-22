#include <stdio.h>
#include <time.h>

void delay(double time);

void delay(double time)
{
	clock_t start = clock(), end = clock();
	double time_diff = 0;
	while (time_diff <= time)
	{
		time_diff = ((double)(end - start))/CLOCKS_PER_SEC;
		end = clock();
		printf("Delay time is %lf\n", time_diff);
		continue;
	}
}

int main(void)
{
	double time;
	printf("Please enter a time for delay:\n");

	while (scanf("%lf", &time) == 1)
	{
		int i = 0;
		if (time < 0)
		{
			printf("Please input a number abow 0:\n");
			continue;
		}
		delay(time);
		while (i++ < 10)
			printf("i = %d\n", i);
		printf("Please enter a time for delay:\n");
	}
	printf("done\n");
	return 0;
}
