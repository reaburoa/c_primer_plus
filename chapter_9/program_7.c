#include <stdio.h>
#include <ctype.h>
#include <string.h>

int get_char_position(char ch);

int main(void)
{
	printf("This program will get char position in alphabet\n");
	char ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
			continue;
		printf("%c %d\n", ch, get_char_position(ch));
	}
	return 0;
}

int get_char_position(char ch)
{
	int position;
	if (isalpha(ch)) 
	{
		position = isupper(ch) ? (ch - 'A' + 1) : (ch - 'a' + 1);
	} 
	else
	{
		position = -1;
	}
	return position;
}
