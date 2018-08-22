#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage %s dest_filename src_filename", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *src_file, *dest_file;
	if ((src_file = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Open file %s failed\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((dest_file = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Open file %s failed\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	int ch;
	long count = 0;
	while ((ch = getc(src_file)) != EOF)
	{
		putc(ch, dest_file);
		count ++;
	}
	fclose(src_file);
	fclose(dest_file);
	fprintf(stdout, "copy %ld chars from %s to %s\n", count,argv[1], argv[2]);
	return 0;
}
