#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1<<30 -1;
const int maxn = 1010;
int n, m, k, cur_del;
int G[maxn][maxn];
bool vis[maxn] = {false};
int block = 0;
int father[maxn];

void init() {
    
    for (int i = 0; i < maxn; i++)
    {
        father[i] = i;
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
        father[faA] = faB;
    }
    
}

int main() {
    // init
    fill(G[0], G[0] + maxn*maxn, INF);
    // input
    int a, b;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        G[a][b] = G[b][a] = 1;
    }

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &cur_del);
        block = 0;
        init();
        fill(vis, vis + maxn, false);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (G[i][j] != INF && (i != cur_del  && j != cur_del))
                {
                    Union(i, j);
                }
                
            }
            
        }

        for (int i = 1; i <= n; i++)
        {
            if (i == cur_del)
            {
                continue;
            }
            int cur_f = findFather(i);
            if (vis[cur_f] == false)
            {
                block++;
                vis[cur_f] = true;
            }
            
        }
        printf("%d\n", block - 1);
        
    }
    return 0;
}