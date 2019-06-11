#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
char S[maxn];
int dp[maxn][maxn];

int main() {
    int ans = 1;
    // init
    fill(dp[0], dp[0] + maxn * maxn, 0);
    // input
    fgets(S, maxn, stdin);
    int len = strlen(S) - 1;
    // boundary
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i < len -1)
        {
            if (S[i] == S[i+1])
            {
                dp[i][i+1] = 1;
                ans = 2;
            }
            else
            {
                dp[i][i+1] = 0;
            }
            
        }
        
    }


    // state tansmit equation
    for (int L = 3; L <= len; L++)
    {
        for (int i = 0; i + L - 1 < len; i++)
        {
            int j = i + L -1;
            if (S[i] == S[j] && dp[i+1][j-1] == 1)
            {
                dp[i][j] = 1;
                ans = L;
            }
            
        }
        
    }
    
    printf("%d", ans);
    return 0;
}