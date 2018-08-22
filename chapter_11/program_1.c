#include <stdio.h>

char *set_arr(char *arr, int n);

int main(void)
{
	int num;
	printf("Please input array members:");
	scanf("%d", &num);
	char ch;
	while (scanf("%c", &ch))
		if (ch == '\n')
			break;
		else
			continue;
	char ar[num];
	printf("Please input source string:");
	set_arr(ar, num);
	int i = 0;
	printf("Array is:\n");
	for (i = 0; i < num; i ++) 
		printf("%c -- %d\n", *(ar + i), *(ar + i));
	return 0;
}

char *set_arr(char *arr, int n)
{
	int i = 0;
	char ch;
	while (i < n)
	{
		ch = getchar();
		if (ch == EOF) {
			break;
		}
		//if (ch == '\n')
		//	continue;
		*(arr + i) = ch;
		i ++;
	}
	*(arr + i) = '\0';

	return arr;
}

