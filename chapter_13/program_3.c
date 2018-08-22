#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "s_gets.h"

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_CONTENTS 200000

int main(void)
{
	printf("Please Input a file:\n");
	char file[MAX_FILE_NAME_LENGTH];
	if (s_gets(file, MAX_FILE_NAME_LENGTH) == NULL)
	{
		fprintf(stderr, "Get file failed");
		exit(EXIT_FAILURE);
	}
	FILE *src_file, *dest_file;
	if ((src_file = fopen(file, "r")) == NULL)
	{
		fprintf(stderr, "open file %s failed\n", file);
		exit(EXIT_FAILURE);
	}
	int ch;
	char *mc = calloc(MAX_FILE_CONTENTS, sizeof(char));
	long int count = 0;
	while ((ch = getc(src_file)) != EOF)
	{
		if (isalpha(ch))
			ch = toupper(ch);
		*(mc + count) = ch;
		count ++;
	}
	if ((dest_file = fopen(file, "w")) == NULL)
	{
		fprintf(stderr, "Open file %s to write failed\n", file);
		exit(EXIT_FAILURE);
	}
	int i = 0;
	for (i= 0; i < count; i ++)
		putc(*(mc + i), dest_file);
	printf("rewrite %ld chars to file %s with upper\n", count, file);
	return 0;
}
