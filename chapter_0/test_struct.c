#include <stdio.h>

typedef struct _ss {
	char str;
	int num;
} ss;

int main()
{
	ss struc = {'a', 10};

	printf("struct str is %c\n", struc.str);
	printf("struct num is %d\n", struc.num);

	return 0;
}
