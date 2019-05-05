#include <cstdio>
int main()
{
	int n = 0, step=0;
	
	scanf("%d", &n);

	if (n<0) {
		return -1;
	}
	else {
		while (n>1) {
			if (n%2==0) {
				n/=2;
			}
			else {
				n=(3*n+1)/2;
			}
			step++;
		}
		printf("%d\n", step);
		return 0;
	}
}