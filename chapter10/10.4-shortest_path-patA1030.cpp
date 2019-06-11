#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 510;
const int INF = (1 << 30) - 1;
int n, G[maxn][maxn];
int st, en, d[maxn], cost[maxn][maxn];
vector<int> pre[maxn], path, tempPath;
int optValue = INF;
bool vis[maxn] = {false};

void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && d[j] < MIN) // 记得主函数里初始化INF
            {
                u = j;
                MIN = d[j];
            }           
        }
        
        if (u == -1)
        {
            return;
        }

        vis[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (vis[v] == false && G[u][v] != INF )
            {
                if(d[v] > d[u] + G[u][v]) {
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
    if (v == st)
    {
        tempPath.push_back(v);
        int value = 0;
        for (int i = tempPath.size() - 1; i > 0; i--)
        {
            int cur = tempPath[i], next = tempPath[i - 1];
            value += cost[cur][next];
        }
        if (value < optValue)
        {
            optValue = value;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }

    tempPath.push_back(v); // note!!!
    for (int i = 0; i < pre[v].size(); i++)
    {
            DFS(pre[v][i]);
    }
    tempPath.pop_back(); // note!!!
    
}

int main() {
    // init
    fill(G[0], G[0] + maxn*maxn, INF);
    fill(cost[0], cost[0] + maxn*maxn, INF);
    // input
    int m;
    scanf("%d%d%d%d", &n, &m, &st, &en);
    for (int i = 0; i < m; i++)
    {
        int a, b, dis, c;
        scanf("%d%d%d%d", &a, &b, &dis, &c);
        G[a][b] = G[b][a] = dis;
        cost[a][b] = cost[b][a] = c;
    }

    Dijkstra(st);
    DFS(en);
    for (int i = path.size() - 1; i >= 0; i--)
    {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[en], optValue);
    
    
    return 0;
}