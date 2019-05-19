#include <cstdio>

int n, now = 0, to, ans = 0;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &to);
        if (to > now)
        {
            ans += (to - now) * 6;
        }
        else 
        {
            ans += (now - to) * 4;
        }


        ans += 5;
        now = to;
        
    }
    
    printf("%d", ans);
    return 0;
}