#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 110;
struct Node
{
    int data;
    int lchild, rchild;
} node[maxn];

int n;
int num[maxn], p = 0;

void inOrder(int root) {
    if (root == -1)
    {
        return;
    }
    inOrder(node[root].lchild);
    node[root].data = num[p++];
    inOrder(node[root].rchild);
}

void LayerOrder(int root) {
    // BFS
    queue<int> q;
    int cnt = 0;
    q.push(root);
    while (!q.empty())
    {
        int now = q.front();
        printf("%d", node[now].data);
        cnt++;
        if (cnt < n)
        {
            printf(" ");
        }
        q.pop();
        if (node[now].lchild != -1)
        {
            q.push(node[now].lchild);
        }
        if (node[now].rchild != -1)
        {
            q.push(node[now].rchild);
        }
    
    }
    
}

int  main() {
    // input
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &node[i].lchild);
        scanf("%d", &node[i].rchild);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    inOrder(0);
    LayerOrder(0);
    return 0;
}