/*活用递推*/
#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 100010, base = 1000000007;
char a[maxn];
int ans = 0;
int main() {
    
    fgets(a, maxn, stdin);
    int n = strlen(a) - 1;

    int l_numP[maxn] = {0}, r_numT = 0;
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            l_numP[i] = l_numP[i-1];
        }
        
        if (a[i] == 'P')
        {
            l_numP[i]++;
        }
        
    }

    for (int i = n - 1; i >= 0; i--)
    {

        // r_numT[i] = r_numT[i+1];
        if (a[i] == 'T')
        {
            r_numT++;
        }

        if (a[i] == 'A')
        {
            ans = (ans + l_numP[i] * r_numT)%base;
        }
    
        
    }

    printf("%d", ans);
    
    
    return 0;
}