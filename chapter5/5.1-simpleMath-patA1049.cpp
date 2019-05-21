#include <cstdio>

int n, now, high, low, b = 1, ans = 0;
int main() {
    scanf("%d", &n);
    while (n/b != 0 )
    {
        now = n/b%10;
        high = n/(b * 10);
        low = n % b;
        if (now == 0)
        {
            ans += high * b;
        }
        else if (now == 1)
        {
            ans += high * b + low + 1;
        }
        else
        {
            ans += (high + 1) * b;
        }

        b *= 10;
    }

    printf("%d", ans);
    
    return 0;
}