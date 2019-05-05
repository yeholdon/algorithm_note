#include <stdio.h>
int main()
{
	double t[3];
	scanf("%lf%lf%lf", &t[0],&t[1],&t[2]);
	for (int i=1; i <= 3; i++) {
		double tmp;
		for (int j=0; j < 3-i; j++) {
			if(t[j]>t[j+1]){
				tmp=t[j];
				t[j]=t[j+1];
				t[j+1]=tmp;
			}
		}
	}
	printf("%.2f %.2f %.2f\n", t[0], t[1], t[2]);
}