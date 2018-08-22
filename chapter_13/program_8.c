#include <stdio.h>
#include <stdlib.h>

int find_char_nums(FILE *fp, char ch);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage %s char [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	char ch = argv[1][0];
	FILE *fp;
	if (argc == 2)
	{
		fp = stdin;
		printf("%c appear %d in stdin\n", ch, find_char_nums(fp, ch));
		if (fclose(fp) != 0)
			printf("Close file failed\n");
	}
	else
	{
		int i = 0;
		for (i = 2; i < argc; i ++)
		{
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				printf("Open file %s failed\n", argv[i]);
				continue;
			}
			printf("%c appear %d in file %s\n", ch, find_char_nums(fp, ch), argv[i]);
			if (fclose(fp) != 0)
				printf("Close file %s failed\n", argv[i]);
		}
	}
	return 0;
}

int find_char_nums(FILE *fp, char ch)
{
	int count = 0;
	int file_ch;
	while ((file_ch = getc(fp)) != EOF)
		if (file_ch == ch) 
			count ++;
	return count;
}

