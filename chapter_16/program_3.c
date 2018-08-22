#include <stdio.h>
#include <math.h>

typedef struct x {
	double r;
	double a;
}s_x;

typedef struct pos {
	double x;
	double y;
} s_pos;

void setPos(s_x *x, s_pos *p);

void setPos(s_x *x, s_pos *p)
{
	static const double deg_rad = 3.1415926 / 180;
	double ang = deg_rad * x->a;
	p->x = x->r * cos(ang);
	p->y = x->r * sin(ang);
}

int main(void)
{
	s_x pa;
	s_pos pos;
	printf("Please input the r and a of the x:");
	while (scanf("%lf %lf", &pa.r, &pa.a) == 2)
	{
		setPos(&pa, &pos);
		printf("X r=%.4lf, a = %.4lf and pos is x=%.4lf y=%.4lf\n", pa.r, pa.a, pos.x, pos.y);

		printf("Please input the r and a of the x:");
	}

	return 0;
}
