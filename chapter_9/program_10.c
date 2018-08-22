#include <stdio.h>

void to_base_n(unsigned long n, int binary);

int main()
{
	unsigned long number;
	printf("Enter an integer (q to quit):\n");
	while (scanf("%lu", &number) == 1) 
	{
		int binary;
		printf("Please input the binary value:");
		scanf("%d", &binary);
		printf("Binary equivalent:");
		to_base_n(number, binary);
		printf("\n");
		printf("Enter an integer (q to quit):\n");
	} 
	return 0;
}

void to_base_n(unsigned long n, int binary)
{
	if (binary < 2 || binary > 10)
	{
		printf("Binary is error and must in 2~10\n");
		return ;
	}
	int r;
	r = n % binary;
	if (n >= binary) 
		to_base_n(n/binary, binary);
	putchar('0' + r);

	return ;
}
