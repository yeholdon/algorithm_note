#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 11;

struct Node
{
    int lchild;
    int rchild;
    Node() {
        lchild = rchild = -1;
    }
} node[maxn];

int n = 0;
int notRoot[maxn] = {0};

void BFS(int index) {
    queue<int> q;
    q.push(index);
    static int cnt = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (cnt != 0)
        {
            printf(" ");
        }
        printf("%d", now);
        cnt++;
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

void inorder(int index) {
    static int cnt = 0;
    if (index == -1)
    {
        return;
    }
    inorder(node[index].lchild);
    if (cnt != 0)
    {
        printf(" ");
    }
    printf("%d", index);
    cnt++;
    inorder(node[index].rchild);
}

int findRoot(int a[], int n) {
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            return i;
        }
        
    }
    return -1;
    
}

int main() {
    // input
    char l, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%*c%c %c", &r, &l);
        if (l == '-')
        {
            node[i].lchild = -1;
        }
        else
        {
            node[i].lchild = l - '0';
            notRoot[l - '0']++;
        }

        if (r == '-')
        {
            node[i].rchild = -1;
        }
        else
        {
            node[i].rchild = r - '0';
            notRoot[r - '0']++;
        }
        
    }

    int root = findRoot(notRoot, n);
    BFS(root);
    printf("\n");
    inorder(root);
    return 0;
}