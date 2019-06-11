#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 210;
const int INF = (1<<30) - 1;

int n, m, G[maxn][maxn], weight[maxn];
int d[maxn], w[maxn], num[maxn], pt[maxn], pre[maxn];
bool vis[maxn] = {false};
map<string, int> strToIndex;
map<int, string> indexToStr;

void Dijkstra(int s) {
    // init
    fill(d, d + maxn, INF);
    fill(vis, vis, false);
    fill(w, w + maxn, 0);
    fill(pt, pt + maxn, 0);

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
                MIN = d[j];
                u = j;
            }
            
        }

        if (u == -1)
        {
            return;
        }
        
        vis[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (vis[v] == false && G[u][v] != INF)
            {
                if (d[v] > d[u] + G[u][v])
                {
                    d[v] = d[u] + G[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                    pt[v] = pt[u] + 1;
                    pre[v] = u;
                }
                else if (d[v] == d[u] + G[u][v])
                {
                    num[v] += num[u];
                    if (w[v] < w[u] + weight[v])
                    {
                        w[v] = w[u] + weight[v];
                        pt[v] = pt[u] + 1;
                        pre[v] = u;
                    }
                    else if (w[v] == w[u] + weight[v])
                    {
                        double uAvg = (w[u] + weight[v])*1.0/(pt[u] + 1);
                        double vAvg = w[v]*1.0/pt[v];
                        if (vAvg < uAvg)
                        {
                            pt[v] = pt[u] + 1;
                            pre[v] = u;
                        }
                         
                    }
                    
                    
                }
                
                
            }
            
        }
        
        
    }
    
}

void printPath(int v) {
    if(v == 0) {
        cout << indexToStr[v];
        return;
    }
    printPath(pre[v]);
    cout << "->" << indexToStr[v];
}

int main() {
    //init
    fill(G[0], G[0] + maxn*maxn, INF);
    //input
    string city1, city2, start;
    cin >> n >> m >> start;
    strToIndex[start] = 0; // set start vectex's index as 0 for convenience
    indexToStr[0] = start;
    for (int i = 1; i < n; i++)
    {
        cin >> city1 >> weight[i];
        strToIndex[city1] = i;
        indexToStr[i] = city1;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> city1 >> city2;
        int c1 = strToIndex[city1];
        int c2 = strToIndex[city2];
        cin >> G[c1][c2];
        G[c2][c1] = G[c1][c2];
    }
    Dijkstra(0);
    int rom = strToIndex["ROM"];
    printf("%d %d %d %d\n", num[rom], d[rom], w[rom], w[rom] / pt[rom]);
    printPath(rom);
    return 0;
}