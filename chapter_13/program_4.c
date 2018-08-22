#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("Usage %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char *failed_file[100];
	int i = 0, j = 0, k = 0;
	for (i = 1; i < argc; i ++)
	{
		FILE *fp;
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			printf("Open file %s failed\n", argv[i]);
			*(failed_file + j) = argv[i];
			j ++;
			continue;
		}
		printf("Print %s file contents:\n", argv[i]);
		int ch;
		while ((ch = getc(fp)) != EOF)
			putc(ch, stdout);
	}
	printf("Open files nums %d\n", argc - 1);
	printf("Opened fialed %d files are:\n", j);
	for (i = 0; i < j; i ++)
		printf("%s\n", *(failed_file + i));
	
	return 0;
}
