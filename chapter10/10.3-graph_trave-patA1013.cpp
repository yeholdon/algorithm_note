#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1<<30 -1;
const int maxn = 1010;
int n, m, k, cur_del;
int G[maxn][maxn];
bool vis[maxn] = {false};
int block = 0;

void init() {
    fill(G[0], G[0] + maxn*maxn, INF);
}

void DFS(int u) {
    if(u == cur_del) {
        return;
    }
    vis[u] = true;
    for (int v = 1; v <= n; v++)
    {
        if (vis[v] == false && G[u][v] != INF)
        {
            DFS(v);
        }
        
    }
    
    
}

void DFSTrave() {
    for (int i = 1; i <= n; i++)
    {
        if (i != cur_del && vis[i] == false)
        {
            block++;
            DFS(i);
        }
        
    }
    
}

int main() {
    // init
    init();
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
        fill(vis, vis + maxn, false);
        DFSTrave();
        printf("%d\n", block - 1);
    }
    
    return 0;
}