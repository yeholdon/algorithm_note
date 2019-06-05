#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 100010;

int maxDepth = 0, maxNum = 0;

struct Node
{
    int depth;
    vector<int> child;
    Node() {
        depth = 0;
    }
} node[maxn];

void BFS(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < node[now].child.size(); i++)
        {
            q.push(node[now].child[i]);
            node[node[now].child[i]].depth = node[now].depth + 1;
            if (node[node[now].child[i]].depth > maxDepth)
            {
                maxDepth = node[node[now].child[i]].depth;
                maxNum = 1;
            }
            else if (node[node[now].child[i]].depth == maxDepth)
            {
                maxNum++;
            }
            
            
        }
        
    }
    
}
int main() {
    int n = 0, father, root;
    double P, r;
    scanf("%d %lf %lf", &n, &P, &r);
    r = r/100.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &father);
        if (father != -1)
        {
            node[father].child.push_back(i);
        }
        else
        {
            root = i;
        }
        
    }

    BFS(root);
    for (int i = 0; i < maxDepth; i++)
    {
        P = P*(1.0+r);
    }

    if (n == 1)
    {
        printf("%.2f 1", P);
        return 0;
    }
    
    printf("%.2f %d", P, maxNum);
    
    
    return 0;
}