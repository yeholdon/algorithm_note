#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;

struct Node
{
    int id, layer;
};

vector<Node> G[maxn];
int n, l, m;
bool inq[maxn];

int BFS(int s, int L) {
    int cnt = 0;
    queue<Node> q;
    Node start;
    start.id = s,
    start.layer = 0;
    q.push(start);
    inq[s] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        int u = now.id;
        for (int i = 0; i < G[u].size(); i++)
        {
            Node next = G[u][i];
            next.layer = now.layer + 1;
            if (inq[next.id] == false && next.layer <= L)
            {
                q.push(next);
                inq[next.id] = true;
                cnt++;
            }
            
        }
        
    }
    return cnt;
    
}

int main() {
    // input
    Node cur;
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++)
    {
        cur.id = i;
        scanf("%d", &m);
        int father;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &father);
            G[father].push_back(cur);
        }
        
    }

    int k, root;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &root);
        fill(inq, inq + maxn, false);
        int cnt = BFS(root, l);
        printf("%d\n", cnt);
    }
    
    
    return 0;
}




/*
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
vector<int> G[maxn];
int n, l, m;
bool vis[maxn];
int cnt = 0;
void DFS(int u, int depth, int l) {
    cnt++;
    vis[u] = true;
    if(depth >= l) return;
    for (int i = 0; i < G[u].size(); i++)
    {
        if (vis[G[u][i]] == false)
        {
            DFS(G[u][i], depth + 1, l);
        }
        
    }
    

}



int main() {
    // input
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        int father;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &father);
            G[father].push_back(i);
        }
        
    }

    int k, root;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &root);
        fill(vis, vis + maxn, false);
        cnt = 0;
        DFS(root, 0, l);
        printf("%d\n", cnt - 1);
    }
    
    
    return 0;
}
*/