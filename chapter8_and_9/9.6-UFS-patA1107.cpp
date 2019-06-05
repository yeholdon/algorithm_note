#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;

// global variables
int father[maxn];
int hobby[maxn] = {0};
int root_num[maxn] = {0};

void init(int n) {
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
        root_num[i] = 0;
        hobby[i] = 0;
    }
    
}

int findFather(int x) {
    int a = x;
    while (x != father[x]) 
    {
        x = father[x];
    }
    
    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }

    return x;
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
    {
        father[faB] = faA;
    }
    
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, k, h;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &h);
            if (hobby[h] == 0)
            {
                hobby[h] = i;
                
            }
            else
            {
                Union(i, hobby[h]);
            }
        }
        
    }

    for (int i = 1; i <= n; i++)
    {
        root_num[findFather(i)]++;
    }
    
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (root_num[i] != 0)
        {
            cnt++;
        }
        
    }
    
    printf("%d\n", cnt);
    sort(root_num + 1, root_num + n + 1, cmp);
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d", root_num[i]);
        if (i < cnt)
        {
            printf(" ");
        }
        
    }
    
    
    return 0;
}