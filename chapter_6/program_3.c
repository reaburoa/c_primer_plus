#include <stdio.h>

int main(void)
{
	int i = 0, j = 0;
	for (i = 0; i < 6; i ++) 
	{
		for (j = 0; j <= i; j ++) 
		{
			printf("%c", 'F'-j);
		}
		printf("\n");
	}

	return 0;
}
