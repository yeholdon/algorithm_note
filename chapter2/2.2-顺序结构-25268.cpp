#include "stdio.h"
#include <math.h>
int main()
{
	double a, b, c, r1, r2;
	scanf("%lf%lf%lf", &a, &b, &c);
	double delta=sqrt(b*b-4*a*c);
	r1 = (-b+delta)/2/a;
	r2 = (-b-delta)/2/a;
	printf("r1=% 7.2f\n", r1);
	printf("r2=% 7.2f", r2);
	return 0;
}