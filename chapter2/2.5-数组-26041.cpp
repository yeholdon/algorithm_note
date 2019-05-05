//杨辉三角
#include <cstdio>
#define MAXN 11
int main() {
	int n=0;
	scanf("%d", &n);
	int a[MAXN] = {1};  
	for (int i = 0; i < n; i++ ) {
		for (int j = 0; j < i ; j++) {
			if (!i) {
				printf("%d\n", i+1);
			}
			
		}
	}