#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
// global variables
int n, m;
int A[maxn];

int binarySearch(int *a, int first, int last, const int value) {
    int mid;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if (value == a[mid])
        {
            return mid;
        }
        else if (value < a[mid])
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
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    // sort the A in ascending order 
    sort(A, A + n);
    
    for (int i = 0; i < n; i++)
    {
        int j = binarySearch(A, 0, n - 1, m - A[i]);
        if (j != -1 && j != i)
        {
            printf("%d %d", A[i], A[j]);
            return 0;
        }
    }

    printf("No Solution");
    
    return 0;
}