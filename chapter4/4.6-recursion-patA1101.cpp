/* method like PATA1093 */

#include <cstdio>
const int maxn = 100010;
const int INF = 1L<<31 - 1;

int a[maxn] = {0}, lnum[maxn], rnum[maxn];
int ans[maxn], num = 0;
int n;
int main() {
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    lnum[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i-1] > lnum[i-1])
        {
            lnum[i] = a[i-1];
        }
        else
        {
            lnum[i] = lnum[i-1];
        }
        
    }

    rnum[n-1] = INF;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i+1] < rnum[i+1])
        {
            rnum[i] = a[i+1];
        }
        else
        {
            rnum[i] = rnum[i+1];
        }
    
    }

    for (int i = 0; i < n; i++)
    {
        if (lnum[i] < a[i] && rnum[i] > a[i])
        {
            ans[num++] = a[i];
        }
        
    }

    printf("%d\n", num);
    for (int i = 0; i < num; i++)
    {
        if (!i)
        {
            printf("%d", ans[i]);
        }
        else
        {
            printf(" %d", ans[i]);
        }
        
        
    }
    printf("\n");
    
    return 0;
}