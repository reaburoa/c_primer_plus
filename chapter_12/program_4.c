#include <stdio.h>

static unsigned int call_num = 0;

int test();

int main()
{
	int i = 0;
	int call_num;
	while (i++ < 10)
		call_num = test();
	printf("Function test() call nums:%d\n", call_num);
	return 0;
}

int test()
{
	printf("This is test function\n");
	return ++ call_num;
}
