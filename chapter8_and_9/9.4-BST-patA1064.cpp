#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;

int CBT[maxn];
int num[maxn];
int n, p = 0;

void inorder(int index) {
    if (index > n)
    {
        return;      
    }
    inorder(index * 2);
    CBT[index] = num[p++];
    inorder(index * 2 + 1);
}

int main() {
    // input
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    sort(num, num + n);
    inorder(1);
    // CBT is in layerorder itself 
    for (int i = 1; i <= n; i++)
    {
        printf("%d", CBT[i]);
        if (i < n)
        {
            printf(" ");
        }
        
    }

    return 0;
}