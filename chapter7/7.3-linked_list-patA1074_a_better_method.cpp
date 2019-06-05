#include <cstdio>
#include <algorithm>

const int maxn = 100010;
struct Node
{
    int address; // node's address
    int data;
    int next;
    int order; // node's order in linked list
} node[maxn];

bool cmp(const Node &a, const Node &b) {
    return a.order < b.order;
}

int first_addr, n, k;
int main() {

    // init
    for (int i = 0; i < maxn; i++)
    {
        node[i].order = maxn;
    }

    // input
    scanf("%d %d %d", &first_addr, &n, &k);

    int addr;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &addr);
        scanf("%d %d", &node[addr].data, &node[addr].next);
        node[addr].address = addr;
    }

    // set order
    int p = first_addr, count = 0;
    while (p != -1)
    {
        node[p].order = count;
        count++;
        p = node[p].next;
    }
    
    // sort
    std::sort(node, node + maxn, cmp);
    // enumerate all count/k integrated blocks
    for (int i = 0; i < count/k; i++)
    {   // No.i block reverse output in reverse
        for (int j = i*k + k - 1; j > i*k; j--)
        {
            node[j].next = node[j-1].address;
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j].next);
        }

        // handle each block's last node's next 
        printf("%05d %d ", node[i*k].address, node[i*k].data);
        if (i != count/k - 1) // not the last integrated block
        {
            node[i*k].next = node[(i+2)*k - 1].address;
            printf("%05d\n", node[i*k].next);
        }
        else // the last integrated block
        {
            if (count%k == 0) // there is no incomplete block
            {
                node[i*k].next = -1;
                printf("-1\n");
            }
            else // there is a incomplete block
            {
                node[i*k].next = node[(i+1)*k].address;
                printf("%05d\n", node[i*k].next);
                for (int j = (i+1)*k; j < count; j++)
                {
                    if (j < count - 1)
                    {
                        printf("%05d %d %05d\n", node[j].address, node[j].data, node[j].next);
                    }
                    else // specify outputing the last node
                    {
                        node[j].next = -1;
                        printf("%05d %d -1\n", node[j].address, node[j].data);
                    }
                    
                }
                
            }
            
        }
        
        
    }
    

    return 0;
}