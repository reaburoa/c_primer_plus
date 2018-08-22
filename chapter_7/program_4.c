#include <stdio.h>

int main(void)
{
	char ch;
	int replace_num = 0;
	while (scanf("%c", &ch) == 1)
	{
		if (ch == '#')
		{
			break;
		}
		if (ch == '.')
		{
			ch = '!';
			printf("%c", ch);
			replace_num ++;
		}
		else if (ch == '!')
		{
			printf("%c%c", ch, ch);
			replace_num ++;
		}
		else
		{
			printf("%c", ch);
		}
	}
	printf("\n");
	printf("replace times %d\n", replace_num);

	return 0;
}
