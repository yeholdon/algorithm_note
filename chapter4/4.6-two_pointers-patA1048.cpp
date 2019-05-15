#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
// global variables
int n, m;
int a[maxn];
int i = 0, j = 0;

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    i = 0;
    j = n-1;
    while (i < j)
    {
        if (a[i] + a[j] == m)
        {
            printf("%d %d", a[i], a[j]);
            return 0;
        }
        else if (a[i] + a[j] < m)
        {
            i++;
        }
        else
        {
            j--;
        }
        
    }
    printf("No Solution\n");

    return 0;
}
