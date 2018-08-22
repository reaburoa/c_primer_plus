#include <stdio.h>

#define IN 0.3937008

int main(void)
{
	float height;
	printf("Please input your height with cm:\n");
	while (scanf("%f", &height) == 1)
	{
		if (height <= 0)
			break;
		printf("%.1f cm = %.2f in\n", height, height * IN);
		printf("Please input your height with cm:\n");
	}
	return 0;
}
