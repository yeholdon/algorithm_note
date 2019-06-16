#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 210;
const int maxl = 10010;

int a[maxn], b[maxl], dp[maxn][maxl];

int main() {
    // input
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }

    int l;
    scanf("%d", &l);
    for (int i = 1; i <= l; i++)
    {
        scanf("%d", &b[i]);
    }
    
    // init boundary
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= l; i++)
    {
        dp[0][i] = 0;
    }

    //state transition equation
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            int MAX = max(dp[i-1][j], dp[i][j-1]);
            if (a[i] != b[j])
            {
                dp[i][j] = MAX;
            }
            else
            {
                dp[i][j] = MAX + 1;
            }
            
            
        }
        
    }
    
    printf("%d", dp[m][l]);
    return 0;
}