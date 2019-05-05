#include <cstdio>
typedef long long LL;
int main() {
	int T = 0;
	int tcnt = 0;
	 scanf("%d", &T);
	 while (T--) {
	 	LL a, b, c, res;
	 	bool flag;
	 	
	 	scanf("%lld%lld%lld", &a, &b, &c);
	 	res = a + b;
	 	if (a>0 && b>0 && res<0) {
	 		flag = true;
	 	}
	 	else if (a<0 && b<0 && res>=0) {
	 		flag = false;
	 	}
	 	else {
	 		if (res > c) {
	 			flag = true;
	 		}
	 		else {
	 			flag = false;
	 		}
	 	}
	 	
	 	if (flag) {
	 		printf("Case #%d: true\n", ++tcnt);
	 	}
	 	else {
	 		printf("Case #%d: false\n", ++tcnt);
	 	}
	 }
	
	return 0;
}
