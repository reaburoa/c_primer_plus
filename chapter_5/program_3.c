#include <stdio.h>

const int WEEK = 7;

int main(void)
{
	int days;
	printf("Please input days:\n");
	while (scanf("%d", &days) == 1)
	{
		if (days <= 0)
			break;
		printf("%d days are %d weeks, %d days\n", days, days / WEEK, days % WEEK);
		printf("Please input days:\n");
	}
	return 0;
}
