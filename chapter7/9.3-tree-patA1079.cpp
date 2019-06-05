#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100010;

double ans = 0.0, P, r;

struct Node
{
    double data;
    vector<int> child;
    Node() {
        data = 0;
    }
} node[maxn];


void DFS(int index, int depth) {
    if (node[index].child.size() == 0)
    {
        // leaf node
        ans += node[index].data * P * pow(1 + r, depth);
        return;
    }
    for (int i = 0; i < node[index].child.size(); i++)
    {
        DFS(node[index].child[i], depth + 1);
    }
    
}


int main() {
    int n, k, tmp;
    scanf("%d %lf %lf", &n, &P, &r);
    r /= 100.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (k == 0)
        {
            scanf("%lf", &node[i].data);
        }
        else
        {
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &tmp);
                node[i].child.push_back(tmp);
            }            
        }
        

        
    }

    DFS(0, 0);
    printf("%.1f\n", ans);
    
}