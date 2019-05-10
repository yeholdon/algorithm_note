/*
1. sort the numbers by ascending order.
2. for each number a[i] binary_search the first number larger than a[i]*p
*/

#include <cstdio>
#include <algorithm> // lower_bound
using namespace std;
const int maxn = 100010;

int n, p, a[maxn], ans = 1;

int main() {
    scanf("%d%d", &n, &p);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // sort
    sort(a, a + n);

    if (n == 1)
    {
        printf("1");
        return 0;
    }
    
    for (int i = 0; i < n; i++)
    {// two numbers at least
        int j = upper_bound(a + i + 1, a + n,  (long long) a[i]*p) - a;
        ans = max(ans, j - i);
    }
    
    printf("%d", ans);
    
    
    return 0;
}