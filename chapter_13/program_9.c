#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

long int get_lines(FILE *fp);

int main(void)
{
	FILE *fp;
	char words[MAX];
	if ((fp = fopen("./file/program_9.data", "a+")) == NULL)
	{
		fprintf(stderr, "Can't open \"wordy\" file\n");
		exit(EXIT_FAILURE);
	}
	long int lines = get_lines(fp);
	puts("Enter words to add the file; press the #");
	puts("key at the begining of a line to terminate.");
	while (fscanf(stdin, "%40s", words) == 1 && words[0] != '#')
	{
		lines ++;
		fprintf(fp, "%d:%s\n", lines, words);
	}
	puts("File contents:");
	rewind(fp);
	while (fscanf(fp, "%40s", words) == 1)
		puts(words);
	puts("Done");
	if (fclose(fp) != 0)
		fprintf(stderr, "Closing file failed\n");
	return 0;
}

long int get_lines(FILE *fp)
{
	long int lines = 0;
	int ch;
	while ((ch = getc(fp)) != EOF)
		if (ch == '\n')
			lines ++;
	rewind(fp);
	return lines;
}
