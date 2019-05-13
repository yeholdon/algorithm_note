#include <cstdio>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

const int maxn = 100010;
const int INF = 1 << 31 -1 ;

map<int, int> sub;
int n, m;
int s[maxn] = {0};

int binarySearch(int *s, int first, int last, int value) {
    int mid;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (value == s[mid])
        {
            return mid;
        }
        else if (value < s[mid])
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
        
    }
    return -1;
    
}


int main() {
    // input
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
        s[i] = s[i-1] + s[i];
    }

    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        int j = binarySearch(s, i, n + 1, s[i - 1] + m);
        if (j != -1)
        {
            sub.insert(pair<int, int>(i, j));
            flag = true;
        }
 
    }

    if (!flag)
    {   // find the sum nearM which is nearest to m
        int nearM = INF;
        for (int i = 1; i <= n; i++)
        {
            int k = upper_bound(s + i, s + n + 1, s[i - 1] + m) - s;
            if (k != n + 1)
            {
                if (s[k] - s[i-1] - m < nearM)
                {
                    nearM = s[k] - s[i-1] - m;
                }
                // sub.insert(pair<int, int>(i, k));
            }
            
        }

        // find the pair whose sum is equal to nearM
        for (int i = 1; i <= n; i++)
        {
            int k = upper_bound(s + i, s + n + 1, s[i - 1] + m) - s;
            if (s[k] - s[i-1] - m == nearM)
            {
                sub.insert(pair<int, int>(i,k));
            }
            
        }
        
        
    }

    // output
    map<int, int >::iterator it;
    for ( it = sub.begin(); it != sub.end(); it++)
    {
        printf("%d-%d\n", it->first, it->second);
    }

    return 0;
}