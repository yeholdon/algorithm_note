#include <cstdio>
#include <algorithm>

const int maxn = 100010;
struct Node
{
    int address; // node's address
    int data;
    int next;
    bool flag; // if the node is in the linked list
} node[maxn];

bool cmp(const Node &a, const Node &b) {
    if(a.flag == false || b.flag == false)
        return a.flag > b.flag;
    else
    {
        return a.data < b.data;
    }
    
}

int first_addr, n;
int main() {

    // init
    for (int i = 0; i < maxn; i++)
    {
        node[i].flag = false;
    }

    // input
    scanf("%d %d", &n, &first_addr);

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
        node[p].flag = true;
        count++;
        p = node[p].next;
    }
    
    if (count == 0)
    {
        printf("0 -1\n");
    }
    else
    {
        // sort
        std::sort(node, node + maxn, cmp);       
        printf("%d %05d\n", count, node[0].address);
        for (int i = 0; i < count; i++)
        {
            if (i != count - 1)
            {
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
            }
            else
            {
                printf("%05d %d -1\n", node[i].address, node[i].data);
            }
            
            
        }
        
    }
    
    return 0;
}