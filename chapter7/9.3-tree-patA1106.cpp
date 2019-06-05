#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
const double INF = 1e12;
vector<int> node[maxn];
int n = 0, num = 0;
double p, r, ans = INF;

void DFS(int index, int depth) {
    if (node[index].size() == 0)
    {
        // leaf node
        double price = p * pow(1 + r, depth);
        if (price < ans)
        {
            ans = price;
            num = 1;
        }
        else if (price == ans)
        {
            num++;
        }
        
        return;
    }
    for (int i = 0; i < node[index].size(); i++)
    {
        DFS(node[index][i], depth + 1);
    }
    
}


int main() {
    int k, tmp;
    scanf("%d %lf %lf", &n, &p, &r);
    r /= 100.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (k != 0)
        {
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &tmp);
                node[i].push_back(tmp);
            }            
        }
        
    }

    DFS(0, 0);
    printf("%.4f %d\n", ans, num);
    
    return 0;
}