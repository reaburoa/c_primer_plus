#include <stdio.h>

int main(void)
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < 6; i ++) 
	{
		int sum = 0;
		for (j = 0; j <= i; j ++) 
		{
			sum += j;
		}
		for (k = 0; k <= i; k ++) 
		{
			printf("%c", 'A' + sum + k);
		}
		printf("\n");
	}

	return 0;
}
