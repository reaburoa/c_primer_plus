#include <stdio.h>

void critic(int *units);

int main(void)
{
	int un;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &un);
	while (un != 56) 
		critic(&un);
	printf("You must have looked it up!\n");
	return 0;
}

void critic(int *units)
{
	printf("No luck, my friend.Try again.\n");
	scanf("%d", units);
}
