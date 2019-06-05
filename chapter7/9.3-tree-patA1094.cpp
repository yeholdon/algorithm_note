#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 110;
vector<int> node[maxn];
int layerNum[maxn] = {0};
int m, n, k, cur, child;

void DFS(int index, int depth) {
    layerNum[depth]++;
    if (node[index].size() == 0)
    {
        return;
    }
    for (int i = 0; i < node[index].size(); i++)
    {
        DFS(node[index][i], depth + 1);
    }
    
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &cur, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            node[cur].push_back(child);
        }
        
    }

    DFS(1, 1);
    int maxValue = -1, maxDepth = 0;
    for (int i = 1; i < maxn; i++)
    {
        if (layerNum[i] > maxValue)
        {
            maxValue = layerNum[i];
            maxDepth = i;
        }
        
    }
    
    printf("%d %d\n", maxValue, maxDepth);
    return 0;
}