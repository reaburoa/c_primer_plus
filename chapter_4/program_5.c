#include <stdio.h>

int main(void)
{
	float speed;
	float file_size;
	float time;
	printf("Please input your network speed:");
	scanf("%f", &speed);
	printf("Please input your file size:");
	scanf("%f", &file_size);
	printf("At %.2f megabits per second, a file of %.2f megabytes\n", speed, file_size);
	printf("download in %.2f seconds\n", (file_size * 8) / speed);

	return 0;
}
