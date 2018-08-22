#include <stdio.h>

int main(void)
{
	int i;
	int start, end;
	printf("Please input table start and end numbers, with white space devide:");
	scanf("%d%d", &start, &end);
	printf("original\tsquare\tcube\n");
	for (i = start; i <= end; i ++) 
	{
		printf("%d\t%ld\t%Le\n", i, (long)i * i, (long double)i * i * i);
	}

	return 0;
}
