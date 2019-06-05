#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1005;

struct Mouse
{
    int weight;
    int rank;
} mouse[maxn];

int ng, np, tmp, group;
queue<int> q;
void clear(queue<int> &q) {
    while (!q.empty())
    {
        q.pop();
    }
}
int main() {
    // nput
    scanf("%d%d", &np, &ng);

    for (int i = 0; i < np; i++)
    {
        scanf("%d", &mouse[i].weight);
    }

    int a;
    clear(q);
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &a);
        q.push(a);
    }
    
    tmp = np;
    // if it is "!q.empty()", it will be a endless loop
    while (q.size() > 1) 
    {   // get the group number
        if (tmp % ng == 0)
        {
            group = tmp/ng;
        }
        else
        {
            group = tmp/ng + 1;
        }

        for (int i = 0; i < group; i++)
        {
            int g_max = q.front();
            for (int j = 0; j < ng; j++)
            {
                // specify the last group
                if (i * ng + j >= tmp)
                {
                    break;
                }
                int cur = q.front();
                if (mouse[cur].weight > mouse[g_max].weight)
                {
                    g_max = cur;
                }
                mouse[cur].rank = group + 1;
                q.pop();
            }
            q.push(g_max);
        }
        
        tmp = group;
        
    }
    // the last one's rank is 1
    mouse[q.front()].rank = 1;

    // output
    for (int i = 0; i < np; i++)
    {
        printf("%d", mouse[i].rank);
        if (i != np - 1)
        {
            printf(" ");
        }
        
    }
    
    return 0;
}