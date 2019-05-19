#include <cstdio>

int n = 0;
double ans = 0.0;
double a;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &a);
        ans += a * i * (n + 1 - i);
    }
    printf("%.2f\n", ans);
    
    return 0;
}