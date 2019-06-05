#include <cstdio>
#include <vector>
#include <algorithm>
//#include <cmath>
using namespace std;
const int maxn = 110;

vector<int> node[maxn];
int leaf[maxn], max_d = 0;

void DFS(int index, int depth) {
    max_d = max(max_d, depth);
    if (node[index].size() == 0)
    {
        leaf[depth]++;
        return;
    }

    for (int i = 0; i < node[index].size(); i++)
    {
        DFS(node[index][i], depth + 1);
    }
    
}

int main() {
    int n, m, parent, child, k;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &parent, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            node[parent].push_back(child);
        }
        
    }

    DFS(1, 1);
    for (int i = 1; i <= max_d; i++)
    {
        if (i != 1)
        {
            printf(" ");
        }
        
        printf("%d", leaf[i]);
    }
    
    return 0;
}