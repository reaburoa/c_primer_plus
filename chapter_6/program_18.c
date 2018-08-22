#include <stdio.h>

#define DUNBAR_NUMBER 150
#define INIT_FRIEND 5

int power(int x, int y);

int main(void)
{
	int week = 1;
	int friends = 0;
	while (friends <= DUNBAR_NUMBER)
	{
		double week_decr = 0;
		int i = 1;
		for (i = 0; i < week; i ++)
		{
			week_decr += 1.0 / power(2, i);
		}
		friends = (INIT_FRIEND - week_decr) * power(2, week);
		printf("week is %2d, friend number is %3d\n", week, friends);
		week ++;
	}
	printf("After %d weeks, Rabnud's friend is %d and lt %d\n", week - 1, friends, DUNBAR_NUMBER);
	return 0;
}

int power(int x, int y)
{
	int sum = 1, i = 1;
	for (i = 1; i <= y; i ++)
	{
		sum *= x;
	}

	return sum;
}
