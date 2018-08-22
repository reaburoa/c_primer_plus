#include <stdio.h>

int main(void)
{
	char pre = 0;
	char next;
	int num = 0;
	while ((next = getchar()) != '#') 
	{
		printf("pre=%c,next=%c\n", pre, next);
		if (pre == 'e' && next == 'i')	
		{
			num ++;
		}
		pre = next;
		printf("There ei num is %d\n", num);
	}

	return 0;
}
