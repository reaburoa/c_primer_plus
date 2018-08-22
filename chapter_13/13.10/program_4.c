#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	double sum = 0;
	int cnt = 0;
	FILE *fp;
	double n;
	if (argc > 2) {
		fprintf(stderr, "Param is error\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 1)
		fp = stdin;
	else if (argc == 2) 
	{
		if ((fp = fopen(argv[1], "r")) == NULL) 
		{
			fprintf(stderr, "open file %s failure\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "useing %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	while (fscanf(fp, "%lf", &n) == 1) 
	{
		cnt ++;
		sum += n;
	}
	fclose(fp);
	if (cnt > 0)
		fprintf(stdout, "all %d number avg is %.4lf\n", cnt, sum / cnt);
	else
		fprintf(stdout, "No valid data\n");
	return 0;
}
