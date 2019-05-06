#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;

struct MoonCake
{
    double store;
    double sum;
    double s_price;
} mcake[maxn];

bool cmp(const MoonCake &a, const MoonCake &b) {
    return a.s_price > b.s_price;
}

int n, D;

int main() {
    
    scanf("%d%d", &n, &D);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &mcake[i].store);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &mcake[i].sum);
        mcake[i].s_price = mcake[i].sum/mcake[i].store;
    }

    // sort 
    sort(mcake, mcake + n, cmp);
    
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mcake[i].store < D)
        {
            ans += mcake[i].sum;
            D -= mcake[i].store;
        }
        else
        {
            ans += D*mcake[i].s_price;
            break;
        }
        
        
    }

    printf("%.2f", ans);
    
    return 0;
}