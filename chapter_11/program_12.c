#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 80

int main(void)
{
	char ch;
	int word_total = 0, upper_total = 0, lower_total = 0, num_total = 0, punct_total = 0;
	bool inword = false;

	printf("Please input a string(with ctrl + D to quit):\n");
	while ((ch = getchar()) != EOF)
	{
		if (isupper(ch))
			upper_total ++;
		else if (islower(ch))
			lower_total ++;
		else if (isdigit(ch))
			num_total ++;
		else if (ispunct(ch))
			punct_total ++;
		if (!isspace(ch) && !inword)
		{
			word_total ++;
			inword = true;
		}
		if (isspace(ch) && inword)
			inword = false;
	}
	printf("word_total=%d, upper_total=%d, lower_total=%d, num_total=%d, punct_total=%d\n", word_total, upper_total, lower_total, num_total, punct_total);
	return 0;
}
