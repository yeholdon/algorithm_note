#include <cstdio>
const int maxn = 100010;

struct Node
{
    int address;
    char data;
    int next;
    bool flag;
} node[maxn];


int h1, h2, n;
int main() {
    // init
    for (int i = 0; i < maxn; i++)
    {
        node[i].flag = false;
    }
    
    // input 
    scanf("%d%d%d", &h1, &h2, &n);
    int addr, next;
    char data;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &addr, &data, &next);
        node[addr].address = addr;
        node[addr].data = data;
        node[addr].next = next;
    }
    
    int p;
    for (p = h1; p != -1; p = node[p].next)
    {
        node[p].flag = true;
    }
    
    for (p = h2; p != -1; p = node[p].next)
    {
        if (node[p].flag == true)
        {
            break;
        }
        
    }

    if (p != -1)
    {
        printf("%05d\n", p);
    }
    else
    {
        printf("-1\n");
    }
 
    return 0;
}