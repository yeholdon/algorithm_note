#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 210;
const int maxl = 10010;

int s[maxl], dp[maxl];
int hashTable[maxn];

int main() {
    // init
    fill(hashTable, hashTable + maxn, -1);
    fill(dp, dp + maxl, 0);
    // input
    int n, m;
    int tmp;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        
        scanf("%d", &tmp);
        hashTable[tmp] = i;
    }
    int l, p = 0;
    scanf("%d", &l);
    int a;
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &a);
        if (hashTable[a] >= 0)
        {
            s[p++] = a;
        }
        
    }

    int ans = -1;
    for (int i = 0; i < p; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (hashTable[s[j]] <= hashTable[s[i]] && dp[j] + 1 > dp[i] )
            {
                dp[i] = dp[j] + 1;
            }
            
        }
        ans = max(ans, dp[i]);
        
    }
    printf("%d", ans);
    
    return 0;
}