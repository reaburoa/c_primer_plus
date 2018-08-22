#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int a = 0;
	a ++;
	if (true) {
		int a = 2;
		printf("inner if block,number a is %d\n", a);
	}

	printf("All block,number a is %d\n", a);
	return 0;
}
