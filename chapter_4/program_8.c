#include <stdio.h>
#define GALLON 3.785

int main(void)
{
	const float METER = 1.609;
	float distance;
	float oil;
	printf("Please input your car run distance:");
	scanf("%f", &distance);
	printf("Please input your car use oil:");
	scanf("%f", &oil);
	printf("Your car runs %.1f feets and take oil %.1f gallon\n", distance, oil);
	printf("Take one gallon oil will run %.1f feet\n", distance/oil);
	float l = oil * GALLON;
	float m = distance * METER;
	printf("take oil per 100 km is %.1fL\n", (l/m) * 100);
	return 0;
}
