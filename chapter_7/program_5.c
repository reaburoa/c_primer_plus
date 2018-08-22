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
		switch (ch)
		{
			case '.':
				ch = '!';
				printf("%c", ch);
				replace_num ++;
				break;
			case '!':
				replace_num ++;
				printf("%c%c", ch, ch);
				break;
			default:
				printf("%c", ch);
				break;
		}
	}
	printf("\n");
	printf("replace times %d\n", replace_num);

	return 0;
}
