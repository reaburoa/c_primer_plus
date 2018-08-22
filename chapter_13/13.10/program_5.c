#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 256

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Using %s char filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (strlen(argv[1]) > 1)
	{
		fprintf(stderr, "the second param must be char");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	char line[LINE_SIZE];
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Open file %s failure\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, LINE_SIZE, fp) != NULL)
	{
		if (strstr(line, argv[1]))
			fputs(line, stdout);
	}
	fclose(fp);
	return 0;
}

