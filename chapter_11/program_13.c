#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
		printf("Please input exec with some params\n");
	else
	{
		int i = 0;
		printf("revert your input command is:\n");
		for (i = argc - 1; i > 0; i --)
			printf("%s ", argv[i]);
		printf("\n");
	}

	return 0;
}
