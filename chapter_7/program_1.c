#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int space_num = 0, new_line_num = 0, other_num = 0;
	while ((ch = getchar()) != '#') 
	{
		if (isblank(ch)) {
			space_num ++;
		}
		else if (ch == '\n') 
		{
			new_line_num ++;
		}
		else
		{
			other_num ++;
		}
	}
	printf("There is %d blank, %d new_line_char, %d other\n", space_num, new_line_num, other_num);

	return 0;
}
