#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 100010;
int pos[maxn];
int main() {

    int n, ans = 0;
    scanf("%d", &n);
    int left = n-1; // count the left num to swap(except for 0)
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        pos[num] = i;
        if (num == i && num != 0)
        {
            left--;
        }
        
    }

    int k = 1;
    while (left > 0)
    {
        if (pos[0] == 0)
        {
            while (k < n)
            {
                // to find the first number which is not at its position.
                if (pos[k] != k)
                {   
                    // in header <algorithm>/<utility>
                    swap(pos[0], pos[k]);
                    ans++;
                    break;
                }
                k++;
            }

            
        }

        while (pos[0] != 0)
        {
            // swap pos[0] and pos[pos[0]]
            swap(pos[0], pos[pos[0]]);
            ans++;
            left--;
        }
    }
    printf("%d", ans);
    return 0;
}