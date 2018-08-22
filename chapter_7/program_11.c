#include <stdio.h>

#define YANGJI_PRICE 2.05
#define TIANCAI_PRICE 1.15
#define HULUOBO_PRICE 1.09
#define FREE 0.05
#define FREE_MONEY 100
#define FREIGHT_5 6.5
#define FREIGHT_20 14
#define FREIGHT_EACH_BANG 0.5

int displayMenu();

int main(void)
{
	displayMenu();
	char menu;
	float yangji_weight = 0;
	float tiancai_weight = 0;
	float huluobo_weight = 0;
	float price = 0;
	while (scanf("%c", &menu) == 1)
	{
		if (menu == 'q') break;
		if (menu < 'a' || menu > 'c') continue;
		printf("Please input weight:");
		float weight = 0;
		scanf("%f", &weight);
		while (getchar() != '\n') continue;
		switch (menu)
		{
			case 'a':
				yangji_weight += weight;
				break;
			case 'b':
				tiancai_weight += weight;
				break;
			case 'c':
				huluobo_weight += weight;
				break;
		}
		displayMenu();
	}
	float free = 0;
	float total_money = yangji_weight * YANGJI_PRICE + tiancai_weight * TIANCAI_PRICE + huluobo_weight * HULUOBO_PRICE;
	if (total_money > FREE_MONEY)
	{
		free = total_money * FREE;
	}
	float freight = 0;
	float all_weight = yangji_weight + tiancai_weight + huluobo_weight;
	if (all_weight <= 5)
	{
		freight = FREIGHT_5;
	}
	else if (all_weight > 5 && all_weight <= 20)
	{
		freight = FREIGHT_20;
	}
	else
	{
		freight = FREIGHT_20 + (all_weight - 20) * FREIGHT_EACH_BANG;
	}
	float all_cost = total_money - free + freight;
	printf("Your cost is below:\n");
	printf("**********************************************************\n");
	printf("item\tweight(pound)\tprice(/pound)\tcost($)\n");
	printf("----------------------------------------------------------\n");
	int items = 0;
	if (yangji_weight > 0)
	{
		items ++;
		printf("yangji\t%.2f\t%.2f\t%.2f\n", yangji_weight,	YANGJI_PRICE, yangji_weight * YANGJI_PRICE);
	}
	if (tiancai_weight > 0)
	{
		items ++;
		printf("tiancai\t%.2f\t%.2f\t%.2f\n", tiancai_weight, TIANCAI_PRICE, tiancai_weight * TIANCAI_PRICE);
	}
	if (huluobo_weight > 0)
	{
		items ++;
		printf("huluobo\t%.2f\t%.2f\t%.2f\n", huluobo_weight, HULUOBO_PRICE, huluobo_weight * HULUOBO_PRICE);
	}
	printf("----------------------------------------------------------\n");
	printf("items:%d\nall_weight:%.2f pounds\nall_money:$%.2f\nfree:$%.2f\nfreight:$%.2f\nall_cost:$%.2f\n", items, all_weight, total_money, free, freight, all_cost);
	printf("**********************************************************\n");
	return 0;
}

int displayMenu()
{
	printf("*****************************************\n");
	printf("a yangji\tb tiancai\n");
	printf("c huluobo\tq quit\n");
	printf("*****************************************\n");
	printf("Please input you buy menu:\n");
	return 0;
}
