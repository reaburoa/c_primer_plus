#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s_gets.h"

#define LEN 40

int main(void)
{
	FILE *in, *out;
	int ch;
	char name[LEN];
	char dest[LEN];
	int count = 0;
	printf("Please input source file:\n");
	if (s_gets(name, LEN) == NULL)
	{
		fprintf(stderr, "get source file name failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Please input dest file:\n");
	if (s_gets(dest, LEN) == NULL)
	{
		fprintf(stderr, "get dest file name failed\n");
		exit(EXIT_FAILURE);
	}
	if ((in = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open file\n", name);
		exit(EXIT_FAILURE);
	}
	if ((out = fopen(dest, "w")) == NULL)
	{
		fprintf(stderr, "Open file %s failed\n", dest);
		exit(EXIT_FAILURE);
	}
	int out_count = 0;
	while ((ch = getc(in)) != EOF)
		if (count ++ % 3 == 0)
		{
			putc(ch, out);
			out_count ++;
		}
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in cloing files\n");
	printf("source file %s has %d chars, zip %s file has %d chars\n", name, count, dest, out_count);
	return 0;
}
