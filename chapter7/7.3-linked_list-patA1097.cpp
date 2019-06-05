#include <cstdio>
#include <algorithm> // abs and sort
#include <cstring>  // for memeset

const int maxn = 100010;

struct Node
{
    int address, data, next;
    int order;
} node[maxn];

bool cmp(const Node &a, const Node &b) {
    return a.order < b.order;
}

bool isExist[10001] = {false}; // data <= 10^4

int main() {
    // memset(isExist, false, sizeof(bool));
    // init
    for (int i = 0; i < maxn; i++)
    {
        node[i].order = 2*maxn;
    }
    
    // input
    int first_addr, n;
    scanf("%d%d", &first_addr, &n);
    int addr;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &addr);
        node[addr].address = addr;
        scanf("%d%d", &node[addr].data, &node[addr].next);
    }
    
    // set order
    int p = first_addr, count = 0, countValid = 0, countRemoved = 0;
    while (p != -1)
    {
        if (isExist[abs(node[p].data)] == true)
        {
            node[p].order = maxn + countRemoved++;
        }
        else
        {
            isExist[abs(node[p].data)] = true;
            node[p].order = countValid++;
        }
        p = node[p].next;
        
    }

    // sort
    std::sort(node, node + maxn, cmp);

    // output
    count = countValid + countRemoved;
    for (int i = 0; i < count; i++)
    {
        if (i != countValid - 1 && i != count - 1)
        {
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);

        }
        else
        {
            printf("%05d %d -1\n", node[i].address, node[i].data);
        }
        
    }
    
    return 0;
}