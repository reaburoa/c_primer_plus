#include<stdio.h>

int main(void)
{
	int limit_number;
	printf("Please input an integer number to get limit below:\n");
	printf("this program will get the limit :\n1.0 + 1.0/2.0 + 1.0/3.0 + ...\n1.0 - 1.0/2.0 + 1.0/3.0 + ...\n");
	double sum_1 = 0, sum_2 = 0;
	scanf("%d", &limit_number);

	int i = 0, j = 0;
	for (i = 1; i <= limit_number; i ++)
	{
		sum_1 += 1.0 / i;
		int j_num = -1;
		for (j = 1; j <= i; j ++) 
		{
			j_num *= -1;
		}
		sum_2 += 1.0 / (i * j_num);
	}

	printf("sum_1=%.4f sum_2=%.4f\n", sum_1, sum_2);

	return 0;
}
