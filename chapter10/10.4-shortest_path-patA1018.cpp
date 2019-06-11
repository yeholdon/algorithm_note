#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 510;
const int INF = (1 << 30) - 1;
int Cmax, n, Sp, m;
int G[maxn][maxn], weight[maxn], d[maxn];
int minNeed = INF, minRemain = INF;
vector<int> pre[maxn], path, tempPath;
bool vis[maxn] = {false};

void Dijkstra(int st) {
    fill(d, d + maxn, INF);
    d[st] = 0;
    for (int i = 0; i <= n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && MIN > d[j])
            {
                MIN = d[j];
                u = j;
            }
            
        }
        if (u ==-1)
        {
            return;
        }
        
        vis[u] = true;
        for (int v = 0; v <= n; v++)
        {
            if (vis[v] == false && G[u][v] != INF)
            {
                if (d[v] > d[u] + G[u][v])
                {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (d[v] == d[u] + G[u][v])
                {
                    pre[v].push_back(u);
                }
                
                
            }
            
        }
        
        
    }
    
}

void DFS(int v) {
    if (v == 0)
    {
        tempPath.push_back(v);
        int need = 0, remain = 0;
        for (int i = tempPath.size() - 1; i >= 0; i--)
        {
            int cur_id = tempPath[i];
            // if this part is difficult to understand, just take a example
            if (weight[cur_id] > 0)
            {
                remain += weight[cur_id];
            }
            else
            {
                if (remain > abs(weight[cur_id]))
                {
                    remain -= abs(weight[cur_id]);
                }
                else // collected bikes have been not enough
                {
                    // need to take from PBMC
                    need += abs(weight[cur_id]) - remain;
                    remain = 0;
                }
                
            }
            
        }
        
        if (minNeed > need)
        {
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        }
        else if (minNeed == need)
        {
            if (minRemain > remain)
            {
                minRemain = remain;
                path = tempPath;
            }
            
        }
        tempPath.pop_back();
        return;

        
    }
    
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++)
    {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();  

}

int main() {
    // init
    fill(G[0], G[0] + maxn * maxn, INF);
    // input

    scanf("%d%d%d%d", &Cmax, &n, &Sp, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &weight[i]);
        weight[i] -= Cmax/2;
    }
    int u, v, t;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &t);
        G[u][v] = G[v][u] = t;
    }

    Dijkstra(0);
    DFS(Sp);
    printf("%d ", minNeed);
    for (int i = path.size() - 1; i >= 0; i--)
    {
        printf("%d", path[i]);
        if (i > 0)
        {
            printf("->");
        }
        
    }
    printf(" %d", minRemain);
    
    return 0;
}