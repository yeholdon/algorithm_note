#include <cstdio>
#include "algorithm"
using namespace std;
const int maxN = 100010;
int dis[maxN] = {0};

int main() {

	int n = 0, m = 0;
	int d[maxN];
	int a, b = 0;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n ; i++) {
		scanf("%d", &d[i]);
		sum = sum + d[i];
		dis[i] = sum;
	}	
	scanf("%d",&m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a > b) {
			swap(a, b);
		}
		int temp = dis[b-1] - dis[a-1];
		printf("%d\n", min(temp, sum - temp));
	}
	return 0;
}
