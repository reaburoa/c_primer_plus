#include <stdio.h>
#include "program_2_h.h"

int main(void)
{
	int mode;

	printf("Enter 0 for metric mode, 1 for US mode:");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		int p_mode = set_mode(mode);
		double distance, oil;
		get_info(p_mode, &distance, &oil);
		show_info(p_mode, distance, oil);
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit):");
		scanf("%d", &mode);
	}
	printf("Done.\n");

	return 0;
}
