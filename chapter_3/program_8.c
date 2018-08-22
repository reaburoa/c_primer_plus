#include <stdio.h>

#define PINGTUO_2_BEI 2
#define BEI_2_ANSHI 8
#define ANSHI_2_DATNAGSHAO 2
#define DATANGSHAO_2_CHASHAO 3

int main(void)
{
	float bei;
	printf("Please input bei:");
	scanf("%f", &bei);
	printf("%.2f bei is %.2f pingtuo\n", bei, bei / PINGTUO_2_BEI * 1.0);
	printf("%.2f bei is %.2f angshi\n", bei, bei * BEI_2_ANSHI * 1.0);
	printf("%.2f bei is %.2f tangshao\n", bei, bei * BEI_2_ANSHI * ANSHI_2_DATNAGSHAO * 1.0);
	printf("%.2f bei is %.2f chashao\n", bei, bei * BEI_2_ANSHI * ANSHI_2_DATNAGSHAO * DATANGSHAO_2_CHASHAO * 1.0);


	return 0;
}
