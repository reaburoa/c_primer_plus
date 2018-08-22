#include <stdio.h>

int main(void)
{
	char letter;
	printf("Please input a capital letter:");
	scanf("%c", &letter);
	int i, diff, j, k;
	char start = 'A';
	char last;
	diff = letter - start + 1;
	for (i = 0; i < diff; i ++) 
	{
		for (k = 0; k < diff - i - 1; k ++) 
		{
			printf(" ");
		}
		for (j = 0; j <= i; j ++) 
		{
			last = start + j;
			printf("%c", last);
		}
		for (j = 1; j <= i; j ++) 
		{
			printf("%c", last - j);
		}
		printf("\n");
	}

	return 0;
}
