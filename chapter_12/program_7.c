#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "program_7_h.h"

int main(void)
{
	int dice, roll;
	int sides;
	int status;
	int sets;
	srand((unsigned int)time(0));
	printf("Enter the number of sets;enter q to stop.\n");
	while (scanf("%d", &sets) == 1)
	{
		printf("How many sides and how many dice?\n");
		if (scanf("%d %d", &sides, &dice) != 2)
		{
			printf("Please input two numbers");
			while (getchar() != '\n')
				continue;
			printf("Let's begin again.\n");
			continue;
		}
		int i = 0;
		printf("Here are %d sets of %d %d-sides throws.\n", sets, dice, sides);
		for (i = 0; i < sets; i ++)
		{
			roll = roll_n_dice(dice, sides);
			printf("%d ", roll);
			if (i != 0 && i % 14 == 0)
				printf("\n");
		}
		printf("\n");
		printf("How many sets?Enter q to quit\n");
	}
	return 0;
}
