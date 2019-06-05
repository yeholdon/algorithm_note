#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n, m, S;
int path[maxn];

struct Node
{
    int w;
    vector<int> child;
} node[maxn];

bool cmp(int a, int b) {
    return node[a].w > node[b].w;
}

void DFS(int index, int depth, int sum) {
    if (sum > S)
    {
        return;
    }
    else if (sum == S)
    {
        if (node[index].child.size() > 0)
        {
            return;
        }
        else
        {   // leaf node, output
            for (int i = 0; i < depth; i++)
            {   
                printf("%d", node[path[i]].w);
                if (i < depth - 1)
                {
                    printf(" ");
                }
                else    printf("\n");
                
            }
            
        }
        return;
        
    }
    else
    {
        for (int i = 0; i < node[index].child.size(); i++)
        {
            int child = node[index].child[i];
            path[depth] = child;
            DFS(child, depth + 1, sum + node[child].w);
        }
        
    }
    
    
    
}
int main() {

    // input
    scanf("%d%d%d", &n, &m, &S);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &node[i].w);
    }

    int parent, k, child;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &parent, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            node[parent].child.push_back(child);
        }
        sort(node[parent].child.begin(), node[parent].child.end(),cmp);
    }
    path[0] = 0;
    DFS(0, 1, node[0].w);
    
    return 0;
}