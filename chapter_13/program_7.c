#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exchange_print(FILE *one, FILE *second);
void exchange_print_line(FILE *one, FILE *second);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage %s file_one file_two\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *one, *second;
	if ((one = fopen(argv[1], "r")) == NULL)
	{
		printf("Open file %s failed\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((second = fopen(argv[2], "r")) == NULL)
	{
		printf("Open file %s failed\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	printf("Print two file with two line:\n");
	exchange_print(one, second);
	printf("Print two file with one line:\n");
	rewind(one);
	rewind(second);
	exchange_print_line(one, second);
	if (fclose(one) != 0 || fclose(second) != 0)
		printf("Closing files failed\n");
	printf("Done\n");
	return 0;
}

void exchange_print(FILE *one, FILE *second)
{
	int ch1, ch2;
	ch1 = getc(one);
	ch2 = getc(second);
	while (ch1 != EOF || ch2 != EOF)
	{
		while (ch1 != EOF && ch1 != '\n')
		{
			putchar(ch1);
			ch1 = getc(one);
		}
		if (ch1 != EOF)
		{
			putchar('\n');
			ch1 = getc(one);
		}
		while (ch2 != EOF && ch2 != '\n')
		{
			putchar(ch2);
			ch2 = getc(second);
		}
		if (ch2 != EOF)
		{
			putchar('\n');
			ch2 = getc(second);
		}
	}
	putchar('\n');
}
void exchange_print_line(FILE *one, FILE *second)
{
	int ch1, ch2;
	ch1 = getc(one);
	ch2 = getc(second);
	while (ch1 != EOF || ch2 != EOF)
	{
		while (ch1 != EOF && ch1 != '\n')
		{
			putchar(ch1);
			ch1 = getc(one);
		}
		if (ch1 != EOF)
		{
	//		putchar('\n');
			ch1 = getc(one);
		}
		while (ch2 != EOF && ch2 != '\n')
		{
			putchar(ch2);
			ch2 = getc(second);
		}
		if (ch2 != EOF)
		{
			putchar('\n');
			ch2 = getc(second);
		}
	}
	putchar('\n');
}

