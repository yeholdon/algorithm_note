#include <cstdio>
int main() {
	//define
	int n;
	int a[1000];
	int ans[6] = {0};
	int count[6] = {0};
	double ans4 = 0;
	//input
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	//caculate
	
	int k = -1;
	int n3 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]%10 == 0) {
			ans[1] += a[i];
			count[1]++;
		}
		
		if (a[i]%5 == 1) {
			k = k*(-1);
			ans[2] = ans[2] + k*a[i];
			count[2]++;
		}
		
		if (a[i]%5 == 2) {
			ans[3]++;
			count[3]++;
		}
		
		if (a[i]%5 == 3) {
			n3++;
			ans[4]+=a[i];
			count[4]++;
		}
		
		if (a[i]%5 == 4) {
			if(ans[5]<a[i]) {
				ans[5] = a[i];
			} 
			count[5]++;
		}
		
	}
	ans4 = ans[4]/((double)n3);
	if (count[1]) {
		printf("%d ", ans[1]);
	}
	else {
		printf("N ");
	}
	if (count[2]) {
		printf("%d ", ans[2]);	
	}
	else {
		printf("N ");
	}
	if (count[3]) {
		printf("%d ", ans[3]);
	}
	else {
		printf("N ");
	}
	if (count[4]) {
		printf("%.1f ", ans4);
	}
	else {
		printf("N ");
	}
	if (count[5]) {
		printf("%d", ans[5]);
	}
	else {
		printf("N");
	}
	//printf("%d %d %d %.1f %d", ans[1], ans[2], ans[3], ans4, ans[5]);
	return 0;
}