#include <stdio.h>

int main(void)
{
	int num;
	int oushu_num = 0;
	int jishu_num = 0;
	long int oushu_sum = 0;
	long int jishu_sum = 0;

	while (scanf("%d", &num) == 1)
	{
		if (num == 0)
		{
			break;
		}

		if (num % 2 == 0)
		{
			oushu_num ++;
			oushu_sum += num;
		}
		else
		{
			jishu_num ++;
			jishu_sum += num;
		}
	}
	double oushu_avg = 0;
	double jishu_avg = 0;
	if (oushu_num > 0)
	{
		oushu_avg = 1.0*oushu_sum/oushu_num;
	}
	if (jishu_num > 0)
	{
		jishu_avg = 1.0*jishu_sum/jishu_num;
	}
	printf("oushu nums %d,oushu avg %.2lf, jishu nums %d, jishu avg %.2lf\n", oushu_num, oushu_avg, jishu_num, jishu_avg);

	return 0;
}
