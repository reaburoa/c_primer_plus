#include <stdio.h>

#define LINE_NUM 8

int main(void)
{
	char ch;
	int ch_num = 0;
	while ((ch = getchar()) != '#')
	{
		if (ch == '\n') 
		{
			ch_num = 0;
			continue;
		}
		ch_num ++;
		printf("%c#%d ", ch, ch);
		if (ch_num % LINE_NUM == 0)
		{
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}
