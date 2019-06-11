#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;

int k, dp[maxn], s[maxn], st[maxn];
bool flag = false;
int main() {
    // init
    dp[0] = s[0];
    st[0] = s[0];
    //input
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &s[i]);
        if(s[i] >= 0)   flag = true;
    }

    for (int i = 0; i < k - 1; i++)
    {
        if (dp[i] + s[i+1] > s[i+1])
        {
            dp[i+1] = dp[i] + s[i+1];
            st[i+1] = st[i];
        }
        else
        {
            dp[i+1] = s[i+1];
            st[i+1] = s[i+1];
        }
    }
    
    // find the minimun in dp
    int ans = 0;
    for (int i = 1; i < k; i++)
    {
        if (dp[i] > dp[ans])
        {
            ans = i;
        }
        
    }
    if (flag == false)
    {
        printf("0 %d %d", s[0], s[k-1]);
    }
    else
    {
        printf("%d %d %d", dp[ans], st[ans], s[ans]);
    }
    
    return 0;
}