#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxv = 10010;
vector<int> G[maxv];
int n, maxh = -1;
int father[maxv];
int vis[maxv];
vector<int> temp, ans;

void init() {
    for (int i = 1; i <= n; i++)
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

void DFS(int u, int depth) {
    vis[u] = true;
    if (depth > maxh)
    {
        maxh = depth;
        temp.clear();
        temp.push_back(u);
    }
    else if(depth == maxh)
    {
        temp.push_back(u);
    }
    
    
    for (int i = 0; i < G[u].size(); i++)
    {
        if (vis[G[u][i]] == false)
        {
            DFS(G[u][i], depth + 1);
        }
        
    }
    
}
int main() {

    // input
    scanf("%d", &n);
    int a, b;
    init(); // init UFS
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
        Union(a, b);
    }

    fill(vis, vis + maxv, false);
    for (int i = 1; i <= n; i++)
    {
        int fa = findFather(i);
        vis[fa] = true;
    }
    int block = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == true)
        {
            block++;
        }
    }

    if (block > 1)
    {
        printf("Error: %d components\n", block);
    }
    else
    {
        fill(vis, vis + maxv, false);
        DFS(1, 1);
        ans = temp;
        fill(vis, vis + maxv, false);
        DFS(temp[0], 1);
        for (int i = 0; i < temp.size(); i++)
        {
            ans.push_back(temp[i]);
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans[0]);
        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i] != ans[i-1]) // banish duplication
            {
                printf("%d\n", ans[i]);
            }
        }
        
    }
    
    return 0;
}