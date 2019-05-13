/**
 * two pointers:
 * According to the feature of the sequence, use two pointer i and j
 * to scan the sequence, which can be in forward direction or backward 
 * 
 * for this problem beacuse the sort owns the time complexity O(nlogn)
 * which is greater than two pointer's O(n) and binarySearch's O(logn), 
 * so they are both ok.
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
// global variables
int n, p;
int a[maxn];
int main() {
    
    //input 
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // sort the a[]
    sort(a, a + n);
    
    int i = 0, j = 0, max = 1;
    
    while (j < n)
    {   // note a[i]*p can be over int here
        while (a[j] <= (long long)a[i]*p && j < n)
        {
            j++;
        }
        if (j - i > max)
        {
            max = j - i;
        }
        i++;
    }

    printf("%d", max);
    
    return 0;
}