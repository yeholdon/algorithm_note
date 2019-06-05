#include <cstdio>
const int maxn = 100010;
struct Node
{
    int data;
    int order;
    int next;
} node[maxn];


int main() {
    int first_addr, addr, n, k;
    int new_first_addr;
    // input 
    scanf("%d %d %d", &first_addr, &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &addr);
        scanf("%d %d", &node[addr].data, &node[addr].next);
        node[addr].order = -1;
    }
    
    // set order
    int p = first_addr, order = 0;
    while (p != -1)
    {
        if (order == k-1)
        {
            new_first_addr = p;
        }
        
        p = node[p].next;
        node[p].order = order;
        order++;
    }
    
    if (order < k)
    {
        new_first_addr = first_addr;
    }
    

    int first, last, tmplast, tmpfirst, next;
    first = first_addr;
    last = first;
    int i = 0, j = 0;
    while (i < order)
    {
        while (j < k - 1 && i + j + 1 < order)
        {
            last = node[last].next;
            j++;
        }
        next = node[last].next;

        // next round needn't reversing
        if (i + k > order)
        {
            break;
        }

        // next round need reversing
        if (i + k + k <= order)
        {
            int tmp = last, q = 0;
            while (q < k)
            {
                tmp = node[tmp].next;
                q++;
            }
            node[last].next = tmp;            
        }
        
        
        while (first != last)
        {
            tmpfirst = node[first].next;
            node[first].next = node[last].next;
            node[last].next = first;
            first = tmpfirst;
        }
        


        i += k;
        j = 0;
        first = next;
        last = first;
    }
    
    p = new_first_addr;
    while (p != -1)
    {

        printf("%05d %d ", p, node[p].data);
        if (node[p].next == -1)
        {
            printf("%d\n", node[p].next);
        }
        else
        {
            printf("%05d\n",  node[p].next);
        }
        
        
        p = node[p].next;
    }
    
    
    return 0;
}