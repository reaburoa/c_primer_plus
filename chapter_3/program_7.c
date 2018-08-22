#include <stdio.h>

#define IN_2_CM 2.54

int main(void)
{
	float in;
	printf("Please input in:");
	scanf("%f", &in);
	printf("%.2f in is %.2f cm\n", in, in * IN_2_CM);
	
	return 0;
}
