#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1020;
const int INF = (1 << 30) - 1;

int n, m, k, Ds;
int G[maxn][maxn], d[maxn];
bool vis[maxn] = {false};

int transID(char *str) {
    if (str[0] == 'G')
    {
        if (str[2] == '0')
        {
            return n + 10;
        }
        return n + str[1] - '0';
    }
    else
    {
        int len = strlen(str), ans = 0;
        for (int i = 0; i < len; i++)
        {
            ans = ans*10 + (str[i] - '0');
        }
        return ans;
    }

    // int i = 0, len = strlen(str), ID = 0;
    // while (i < len) {
    //     if (str[i] != 'G')
    //     {
    //         ID = ID * 10 + (str[i] - '0');
    //     }
    //     i++;
        
    // }
    // if (str[0] == 'G')
    // {
    //     return n + ID;
    // }
    // else
    // {
    //     return ID;
    // }
     
}

void Dijkstra(int s) {
    // init
    fill(vis, vis + maxn, false);
    fill(d, d + maxn, INF);
    d[s] = 0;
    for (int i = 0; i < n + m; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n + m; j++)
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
        for (int v = 1; v <= n + m; v++)
        {
            if (vis[v] == false && G[u][v] != INF && d[v] > d[u] + G[u][v])
            {
                d[v] = d[u] + G[u][v];
            }
            
        }
        
        
        
    }
    
}

int main() {
    // init
    fill(G[0], G[0] + maxn*maxn, INF);
    // input
    scanf("%d%d%d%d", &n, &m, &k, &Ds);
    
    for (int i = 0; i < k; i++)
    {
        char p1[5], p2[5];
        int dis, a, b;
        scanf("%s %s %d", p1, p2, &dis);
        a = transID(p1);
        b = transID(p2);
        // printf("%d %d\n", a, b);
        G[a][b] = G[b][a] = dis;
    }
    double ansDis = -1, ansAvg = INF;
    int ansIndex = -1;
    for (int i = n + 1; i <= n + m; i++)
    {
        double minDis = INF, avg = 0;
        Dijkstra(i);
        for (int j = 1; j <= n; j++)
        {
            if (d[j] > Ds)
            {
                minDis = -1;
                break;
            }
            
            if (d[j] < minDis)
            {
                minDis = d[j];
                // minIndex = i;
            }
            avg += 1.0*d[j]/n;
        }
        if (minDis == -1)
        {
            continue;
        }
        
        if (minDis > ansDis)
        {
            ansDis = minDis;
            ansIndex = i;
            ansAvg = avg;
        }
        else if (minDis == ansDis)
        {
            if (ansAvg > avg)
            {
                // ansDis = minDis;
                ansIndex = i;
                ansAvg = avg;
            }
            
        }
        
        
        
        
    }
    if (ansIndex == -1)
    {
        printf("No Solution\n");
    }
    else
    {
        printf("G%d\n", ansIndex - n);
        printf("%.1f %.1f\n", ansDis, ansAvg);
    }
    
    
    
    return 0;
}