#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 510;
const int INF = 1 << 30 - 1;
int n, G[maxn][maxn];
int d[maxn], w[maxn], weight[maxn], num[maxn];
bool vis[maxn] = {false};

void Dijkstra(int s) {
    // init
    fill(d, d + maxn, INF);
    fill(w, w + maxn, -1);
    fill(num, num + maxn, 0);
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
            
        }
        if (u == -1)
        {
            return;
        }
        vis[u] = true; // don't forget
        for (int v = 0; v < n; v++)
        {
            if (vis[v] == false && G[u][v] != INF)
            {
                if (d[v] > d[u] + G[u][v])
                {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                }
                else if (d[v] == d[u] + G[u][v])
                {
                    num[v] += num[u];   
                    if( w[v] < w[u] + weight[v])
                    {
                       w[v] = w[u] + weight[v];
                    }
                    
                }
                
                
            }
            
        }
        
    }
    
}


int main() {
    // init
    fill(weight, weight + maxn, 0);
    // the Graph must be initialized!!!
    fill(G[0], G[0] + maxn * maxn, INF);
    // input
    // 1.N, M(number of roads), C1(start point), C2(target point)
    int m, s, t, c1, c2, L;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    // 2. N integers for weight of every node
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    // 3. M lines. each line with c1, c2 and L
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &c1, &c2, &L);
        G[c1][c2] = G[c2][c1] = L;
    }
    
    Dijkstra(s);

    // output
    printf("%d %d", num[t], w[t]);
    
    return 0;
}


/* heap optimizing version
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 510;
const int INF = 1 << 30 - 1;
int n, G[maxn][maxn];
int d[maxn], w[maxn], weight[maxn], num[maxn];
bool vis[maxn] = {false};
struct cp
{
    int index;
    int dis;
    friend bool operator<(cp a, cp b) {
        return a.dis > b.dis;
    }
};

priority_queue<cp> pq;

void Dijkstra(int s) {
    // init
    fill(d, d + maxn, INF);
    fill(w, w + maxn, -1);
    fill(num, num + maxn, 0);
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    cp st;
    st.index = s;
    st.dis = d[s];
    pq.push(st);
    while (!pq.empty())
    {
        cp now = pq.top();
        pq.pop();
        int u = now.index;
        if(d[u] < now.dis) continue; // note!!!
        vis[u] = true; // don't forget
        for (int v = 0; v < n; v++)
        {
            if (vis[v] == false && G[u][v] != INF)
            {
                if (d[v] > d[u] + G[u][v])
                {
                    d[v] = d[u] + G[u][v];
                    cp tmp;
                    tmp.dis = d[v];tmp.index = v;
                    pq.push(tmp);
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                }
                else if (d[v] == d[u] + G[u][v])
                {
                    num[v] += num[u];   
                    if( w[v] < w[u] + weight[v])
                    {
                        w[v] = w[u] + weight[v];
                    }
                    
                }
                
                
            }
            
        }
        
    }
    

}


int main() {
    // init
    fill(weight, weight + maxn, 0);
    // the Graph must be initialized!!!
    fill(G[0], G[0] + maxn * maxn, INF);
    // input
    // 1.N, M(number of roads), C1(start point), C2(target point)
    int m, s, t, c1, c2, L;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    // 2. N integers for weight of every node
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    // 3. M lines. each line with c1, c2 and L
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &c1, &c2, &L);
        G[c1][c2] = G[c2][c1] = L;
    }
    
    Dijkstra(s); 

    // output
    printf("%d %d", num[t], w[t]);
    
    return 0;
}
*/