#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	int char_total = 0;
	int new_line_total = 0;
	int int_total = 0;
	int letter_total = 0;
	FILE *fp;
	printf("this program will read the file ../files/program_1.txt\n");
	char file_name[25] = "files/program_1.txt";
	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		printf("Failed to open file\n");
		exit(1);
	}
	char ch;
	while ((ch = getc(fp)) != EOF) 
	{
		char_total ++;
        if (isdigit(ch))
		{
		    int_total ++;
		}
		if (isalpha(ch))
		{
			letter_total ++;
		}
		if (isspace(ch))
		{
			new_line_total ++;
		}
	}
	printf("There is %d chars and letter is %d and digit is %d and not print char is %d\n", char_total, letter_total, int_total, new_line_total);
	return 0;
}
