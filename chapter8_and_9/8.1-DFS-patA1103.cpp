#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// global variables
int n, k, p;
vector<int> fac;

int initSearchRange() {
    int m = 0;
    while (pow(m, p) <= n)
    {
        fac.push_back(pow(m, p));
        m++;
    }
    return m;
}

int maxSumFac = 0;
vector<int> tmp, ans;

void DFS(int index, int nowK, int sum, int sumFac) {
    if (index < 1 || nowK > k || sum > n)
    {
        return;
    }

    if (nowK == k && sum == n)
    {
        if (sumFac > maxSumFac)
        {
            maxSumFac = sumFac;
            ans = tmp;
        }
        return;
    }
    
    // select index
    if (sum + fac[index] <= n && nowK + 1 <= k)
    {
        tmp.push_back(index);
        DFS(index, nowK + 1, sum + fac[index], sumFac + index);
        tmp.pop_back();
    }
    
    // don't select index
    DFS(index - 1, nowK, sum, sumFac);
    
}
int main() {
    // input 
    scanf("%d%d%d", &n, &k, &p);
    
    int m = initSearchRange();

    DFS(m - 1, 0, 0, 0);

    if (ans.size() == 0)
    {
        printf("Impossible\n");
    }
    else
    {
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); i++)
        {
            printf("%d^%d", ans[i], p);
            if (i != ans.size() - 1)
            {
                printf(" + ");
            }
            
        }
        
    }
    
    
    return 0;
}