#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int up_char_nums = 0;
	int lower_char_nums = 0;
	int other_char_nums = 0;
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (isupper(ch))
		{
			up_char_nums ++;
		}
		else if (islower(ch))
		{
			lower_char_nums ++;
		}
		else
		{
			other_char_nums ++;	
		}
	}

	printf("Upper char nums is %d, lower char nums is %d and other char nums is %d\n", up_char_nums, lower_char_nums, other_char_nums);
	return 0;
}
