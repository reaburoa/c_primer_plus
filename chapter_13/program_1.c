#include <stdio.h>
#include <stdlib.h>

#include "s_gets.h"
#define FILE_NAME_LENGTH 100

int main(void)
{
	printf("Please input a file name:\n");
	char file[FILE_NAME_LENGTH];
	if (s_gets(file, FILE_NAME_LENGTH) == NULL)
	{
		fprintf(stderr, "get file name failed\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	if ((fp = fopen(file, "r")) == NULL)
	{
		printf("Open file %s failed\n", file);
		exit(EXIT_FAILURE);
	}
	int ch;
	long count = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		putc(ch, stdout);
		count ++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", file, count);

	return 0;
}
