#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double ar[], int n);
double *new_d_array(int n, ...);

int main(void)
{
	double *p1;
	double *p2;

	p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
	p2 = new_d_array(4, 100.0, 20.0, 8.08, -1890.0);
	show_array(p1, 5);
	show_array(p2, 4);
	free(p1);
	free(p2);

	return 0;
}

void show_array(const double ar[], int n)
{
	int i = 0;
	for (i = 0; i < n; i ++)
	{
		printf("%-.4lf ", ar[i]);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");
}

double *new_d_array(int n, ...)
{
	va_list ap; // 创建一个存储变量内容的对象
	int i;
	double *p1 = malloc(n*sizeof(double));
	va_start(ap, n); // 将ap初始化为参数列表
	for (i = 0; i < n; i ++)
		*(p1 + i) = va_arg(ap, double);	// 依次获取参数
	va_end(ap); // 清理内存

	return p1;
}

