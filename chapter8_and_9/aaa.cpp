#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxv = 1000;// 最大顶点数
const int INF = (1<<30) - 1;

vector<int> Adj[maxv];
int n, G[maxv][maxv];
bool inq[maxv] = {false};

void init() {
    // 需要根据输入先初始化G[][]
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (inq[v] == false && G[u][v] != INF)
            {
                q.push(v);
                inq[v] = true;
            }
            
        }
        
    }
    
}

void BFSTrave() {
    for (int u = 0; u < n; u++)
    {
        if (inq[u] == false)
        {
            BFS(u);
        }
        
    }
    
}
