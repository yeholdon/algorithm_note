#include <cstdio>

typedef long long LL;
int main()
{
	int T = 0, num = 0;
	LL A, B, C;
	scanf("%d", &T);
	while (T--) {
		num++;
		scanf("%lld%lld%lld", &A, &B, &C);
		if (A + B > C) {
			printf("Case # %d:true\n", num);
		}
		else {
			printf("Case # %d:false\n", num);
		}
		
	}
	return 0;
}
