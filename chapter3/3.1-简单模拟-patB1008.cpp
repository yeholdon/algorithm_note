#include <cstdio>

int main() {
int a[100];
int n, m, count = 0;

scanf("%d%d", &n, &m);
for (int i = 0; i < n; i++) {
	scanf("%d", &a[i]);
	
}

m%=n;

for (int i = n-m; i < n; i++) {
	printf("%d", a[i]);
	if (++count < n) {
		printf(" ");
	}
}
for (int i = 0; i < n-m; i++) {
	printf("%d", a[i]);
	if (++count < n) {
		printf(" ");
	}
}

return 0;
}