#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxm = 110;

int dp[maxn][maxm] = {0};
int w[maxn], choice[maxn][maxm];
int n, m;
bool flag[maxn] = {false};

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    // init
    fill(w, w + maxn, 0);
    fill(dp[0], dp[0] + maxn*maxm, 0);
    fill(choice[0], choice[0] + maxn * maxm, 0);
    // input
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }

    sort(w + 1, w + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            if (dp[i-1][j] <= dp[i-1][j-w[i]] + w[i])
            {
                dp[i][j] = dp[i-1][j-w[i]] + w[i];
                choice[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
                choice[i][j] = 0;
            }
            
            
        }
        
    }
    

    if (dp[n][m] != m)
    {
        printf("No Solution\n");
    }
    else
    {
        int k = n, num = 0, v = m;
        while (k >= 1)
        {
            if (choice[k][v] == 1)
            {
                flag[k] = true;
                v -= w[k];
                num++;
            }
            else
            {
                flag[k] = false;
            }
            k--;
            
        }
        
        for (int i = n; i >= 1; i--)
        {
            if (flag[i] == true)
            {
                printf("%d", w[i]);
                num--;
                if (num > 0)
                {
                    printf(" ");
                }
                
            }
            
        }

    }
    
    
    return 0;
}