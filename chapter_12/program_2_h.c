#include <stdio.h>

static int mode = 0;
static double distance;
static double oil;

void set_mode(int p_mode)
{
	if (p_mode != 0 && p_mode != 1)
	{
		printf("Invalid mode specified.Mode 1(US) used.\n");
		p_mode = 1;
	}
	mode = p_mode;
}

void get_info()
{
	if (mode == 0) 
	{
		printf("Enter distance traveled in kilometers:");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in liters:");
		scanf("%lf", &oil);
	}
	else if (mode == 1)
	{
		printf("Enter distance trvaeled in miles:");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in gallons:");
		scanf("%lf", &oil);
	}
}

void show_info()
{
	if (mode == 0)
		printf("Fuel consumption is %.2lf liters per 100 km.\n", (oil / distance) * 100);
	else if (mode == 1)
		printf("Fuel consumption is %.2lf miles per gallon.\n", (distance / oil));
}
