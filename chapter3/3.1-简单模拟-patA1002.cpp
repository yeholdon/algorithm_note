#include <cstdio>

const int maxN = 1010;
int main() {
	
	double p[maxN] = {0};
	int n = 0, m = 0;
    double k = 0.0;
	int cnt = 0;

    scanf("%d", &n);
    for(int  i = 0; i < n; i++)
    {
        scanf("%d%lf", &m, &k);
        p[m] += k;
    }
    scanf("%d", &n);
    for(int  i = 0; i < n; i++)
    {
        scanf("%d%lf", &m, &k);
        p[m] += k;
    }
	
	for (int i = 0; i < maxN; i++) {
        if (p[i] != 0) {
            cnt++;
        }
        
		
	}
	
    printf("%d", cnt);
    for(int  i = maxN - 1; i >= 0; i--)
    {
        if (p[i] != 0) {
            printf(" %d %.1f", i, p[i]);
        }
 
    }
    
	return 0;
}