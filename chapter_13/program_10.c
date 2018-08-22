#include <stdio.h>
#include <stdlib.h>

#include "s_gets.h"

#define MAX 41

int main(void)
{
	char file[MAX];
	printf("Please input a file name:\n");
	if (s_gets(file, MAX) == NULL)
	{
		fprintf(stderr, "Get file name error\n");
		exit(EXIT_FAILURE);
	}
	int seek;
	FILE *fp;
	if ((fp = fopen(file, "r")) == NULL)
	{
		fprintf(stderr, "Open file %s failed\n", file);
		exit(EXIT_FAILURE);
	}
	printf("please input a number to seek file (-1 to quit):\n");
	rewind(fp);
	long int pos;
	int ch;
	while (scanf("%d", &seek) == 1)
	{
		if (seek < 0)
			break;
		pos = (long) seek * sizeof(char);
		fseek(fp, pos, SEEK_SET);
		while ((ch = getc(fp)) != '\n')
			putchar(ch);
		putchar('\n');
		printf("please input a number to seek file (-1 to quit):\n");
	}
	return 0;
}
