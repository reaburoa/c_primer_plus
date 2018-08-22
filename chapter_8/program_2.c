#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int line_num = 10;
	int char_totals = 0;
	while ((ch = getchar()) != EOF)
	{
		if (isspace(ch))
		{
			switch (ch)
			{
				case '\t':
					printf("\\t");
					break;
				case '\n':
					printf("\\n");
					break;
				case '\b':
					printf("\\b");
					break;
			}
			printf("#%d", ch);
		}
		else if (iscntrl(ch))
		{
			printf("#%d", ch);
		}
		else
		{
			printf("%c#%d ", ch, ch);
		}
		char_totals ++;
		if (char_totals % 10 == 0)
		{
			printf("\n");
		}
		if (ch == '\n')
		{
			char_totals = 0;
		}
	}
	printf("This program will exit\n");
	return 0;
}
