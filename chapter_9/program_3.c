#include <stdio.h>

void chline(char ch, int column, int row);

int main(void)
{
	char ch;
	int column, row;
	printf("This program will print a char\n");
	printf("Please enter a char to print('#' to quit):");
	while (scanf("%c", &ch) == 1) 
	{
		if (ch == '#') 
			break;
		if (ch == '\n')
			continue;
		printf("The %c will print row and column,please enter row and column:", ch);
		if (scanf("%d %d", &row, &column) != 2)
			break;
		chline(ch, column, row);
		printf("Please enter a char to print('#' to quit):");
	}
	return 0;
}

void chline(char ch, int column, int row)
{
	int i, j;
	for (i = 0; i < row; i ++)
	{
		for (j = 0; j < column; j ++)
			putchar(ch);
		putchar('\n');
	}
}
